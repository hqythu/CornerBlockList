//
// Created by ZhuangTianYi on 15/6/21.
//

#include "CornerBlockList.h"

#include "common.h"
#include "Edge.h"

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>


CornerBlockList::CornerBlockList() {
    block_num = pair_num = 0;

    E = W = N = S = nullptr;
}

// TODO
CornerBlockList::CornerBlockList(const std::string &file_name) {
    std::ifstream fin;
    fin.open(file_name);

    if (!fin.is_open())
        std::cerr << "ERROR: FILE NOT OPEN" << std::endl;

    fin >> block_num;

    for (int i = 0; i < block_num; i++) {
        if (fin.eof()) {
            std::cerr << "ERROR: FILE ENDING!" << std::endl;
            break;
        }

        double width, height;
        fin >> width >> height;
        rectangles.push_back(Rectangle(width, height));
    }

    // check rectangle read ending
    {
        double tmp1, tmp2;
        fin >> tmp1 >> tmp2;
        if (tmp1 != 0 || tmp2 != 0)
            std::cerr << "ERRPR: input data error.";
    }
    fin >> pair_num;
    for (int i = 0; i < pair_num; i++) {
        int rec1_id, rec2_id;
        fin >> rec1_id >> rec2_id;
        pairs.push_back(std::make_pair(rec1_id - 1, rec2_id - 1));
    }

    fin.close();

//    block_ids.clear();
//    orientations.clear();

    std::srand(std::time(nullptr));

    //initial the Corner Block List
    con = new Content();
    for (int i = 0; i < block_num; i++) {
        con->block_ids.push_back(i);
        con->ifrotate.push_back(0);
    }
    std::random_shuffle(con->block_ids.begin(), con->block_ids.end());
    for (int i = 1; i < block_num; i++)
        con->orientations.push_back(rand() % 2);

    for (int i = 1; i < block_num; i++)
        con->uncover_rec_num.push_back(0);

}

void CornerBlockList::show() {
    Visualizer visualizer(N->dis, E->dis);
    visualizer.show(rectangles);
}

void CornerBlockList::optimize() {
    double temp = INIT_TEMP;
    double now = assess(con);
    while (temp > GOAL_TEMP) {
        std::cout << temp << std::endl;
        for (int i = 1; i <= EVERY; i++) {
            Content *tmp = RandomChange(con);
            double next = assess(tmp);
            if ((next > 0) && ((next < now) || ((rand() % 1000) / 1000 < exp(now - next/ temp)))) {
                delete con;
                con = tmp;
            } else {
                delete tmp;
            }
        }
        temp *= 0.95;
    }
}

bool CornerBlockList::build(const Content *con) {
    HStack.clear();
    VStack.clear();
    E = new Node();
    W = new Node();
    S = new Node();
    N = new Node();

    for (int i = 0; i < block_num; i++) {
        rectangles[i].get_V()->SetLen(rectangles[i].get_height(con->ifrotate[i]));
        rectangles[i].get_H()->SetLen(rectangles[i].get_width(con->ifrotate[i]));
    }

    Edge *e = rectangles[con->block_ids[0]].get_V();
    e->SetS(S);
    e->SetT(N);
    N->Go_in++;

    e = rectangles[con->block_ids[0]].get_H();
    e->SetS(W);
    e->SetT(E);
    E->Go_in++;

    int p = 0;
    for (int i = 1; i < block_num; i++) {
        int now = con->block_ids[i];
        int num = 1;
        while (con->uncover_rec_num[p]) {
            num++;
            p++;
        }
        p++;
        if (con->orientations[i - 1]) {
            //Check
            if (num > VStack.size())
                return false;

            //build H Graph
            Node *s1 = (rectangles[VStack[VStack.size() - num]].get_H())->GET_S();

            Edge *e = rectangles[now].get_H();
            e->SetS(s1);
            e->SetT(E);
            s1->Add(e);
            E->Go_in++;

            //build V Graph
            Node *nod = new Node();

            for (int j = 1; j <= num; j++)
                (rectangles[VStack[VStack.size() - j]].get_V())->SetT(nod);
            nod->Go_in = num;
            e = rectangles[now].get_V();
            e->SetS(nod);
            e->SetT(N);
            nod->Add(e);
            N->Go_in -= (num - 1);

            //push
            HStack.push_back(now);
            for (int j = 1; j <= num; j++)
                VStack.pop_back();
            VStack.push_back(now);
        } else {
            //Check
            if (num > HStack.size())
                return false;

            //build V Graph
            Node *s1 = (rectangles[HStack[HStack.size() - num]].get_V())->GET_S();

            Edge *e = rectangles[now].get_V();
            e->SetS(s1);
            e->SetT(N);
            s1->Add(e);
            N->Go_in++;

            //build H Graph
            Node *nod = new Node();
            for (int j = 1; j <= num; j++)
                (rectangles[HStack[HStack.size() - j]].get_H())->SetT(nod);
            e = rectangles[now].get_H();
            e->SetS(nod);
            e->SetT(E);
            nod->Add(e);
            E->Go_in -= (num - 1);
            //push
            VStack.push_back(now);
            for (int j = 1; j <= num; j++)
                HStack.pop_back();
            HStack.push_back(now);
        }
    }
    return true;
}

void CornerBlockList::cal_longest(Node *start) {
    std::vector<Node *> nod_array;
    nod_array.push_back(start);
    int head = 0;
    int tail = 0;

    for (head = 0, tail = 0; head <= tail; head++) {
        for (int i = 0; i < (nod_array[head]->edges).size(); i++) {
            Node *tmp = ((nod_array[head]->edges)[i])->GET_T();
            if (!(--tmp->Go_in)) {
                tail++;
                nod_array.push_back(tmp);
            }
        }
    }
    //initial
    for (int i = 0; i < tail; i++)
        nod_array[i]->dis = 0;
    //calculate the longest distance
    for (int i = 0; i < tail; i++) {
        Node *st = nod_array[i];
        for (int j = 0; j < st->edges.size(); j++) {
            Node *ed = (st->edges[j])->GET_T();
            double l = (st->edges[j])->GET_LEN();
            ed->dis = (ed->dis > (st->dis + l) ? ed->dis : (st->dis + l));
        }
    }
}

void CornerBlockList::kill() {
    for (int i = 0; i < block_num; i++) {
        Node *nd = rectangles[i].get_H()->GET_S();
        if (nd) delete nd;
        nd = rectangles[i].get_H()->GET_T();
        if (nd) delete nd;
        nd = rectangles[i].get_V()->GET_S();
        if (nd) delete nd;
        nd = rectangles[i].get_V()->GET_T();
        if (nd) delete nd;
    }
}

double CornerBlockList::assess(const Content *c) {
    double q = build(c);
    //Check
    double ret = -1;
    if (q) {
        cal_longest(S);
        cal_longest(W);
        double area = (N->dis) * (E->dis);
        double wire = 0;
        for (int i = 0; i < pair_num; i++) {
            //Horizon wire
            double x1 = (rectangles[pairs[i].first].get_H()->GET_S())->dis +
                        rectangles[pairs[i].first].get_width(c->ifrotate[pairs[i].first]) / 2;
            double y1 = (rectangles[pairs[i].first].get_H()->GET_T())->dis -
                        rectangles[pairs[i].first].get_width(c->ifrotate[pairs[i].first]) / 2;
            double x2 = (rectangles[pairs[i].second].get_H()->GET_S())->dis +
                        rectangles[pairs[i].second].get_width(c->ifrotate[pairs[i].second]) / 2;
            double y2 = (rectangles[pairs[i].second].get_H()->GET_T())->dis -
                        rectangles[pairs[i].second].get_width(c->ifrotate[pairs[i].second]) / 2;
            if (x2 > y1) {
                wire += (x2 - y1);
                rectangles[pairs[i].first].set_X(y1);
                rectangles[pairs[i].second].set_X(x2);
            }
            else if (x1 > y2) {
                wire += (x1 - y2);
                rectangles[pairs[i].first].set_X(x1);
                rectangles[pairs[i].second].set_X(y2);
            } else {
                rectangles[pairs[i].first].set_X((x1 > x2 ? x1 : x2));
                rectangles[pairs[i].second].set_X((x1 > x2 ? x1 : x2));
            }

            //Vertical wire
            x1 = (rectangles[pairs[i].first].get_V()->GET_S())->dis +
                 rectangles[pairs[i].first].get_height(c->ifrotate[pairs[i].first]) / 2;
            y1 = (rectangles[pairs[i].first].get_V()->GET_T())->dis -
                 rectangles[pairs[i].first].get_height(c->ifrotate[pairs[i].first]) / 2;
            x2 = (rectangles[pairs[i].second].get_V()->GET_S())->dis +
                 rectangles[pairs[i].second].get_height(c->ifrotate[pairs[i].second]) / 2;
            y2 = (rectangles[pairs[i].second].get_V()->GET_T())->dis -
                 rectangles[pairs[i].second].get_height(c->ifrotate[pairs[i].second]) / 2;
            if (x2 > y1) {
                wire += (x2 - y1);
                rectangles[pairs[i].first].set_Y(y1);
                rectangles[pairs[i].second].set_Y(x2);
            }
            else if (x1 > y2) {
                wire += (x1 - y2);
                rectangles[pairs[i].first].set_Y(x1);
                rectangles[pairs[i].second].set_Y(y2);
            } else {
                rectangles[pairs[i].first].set_Y((x1 > x2 ? x1 : x2));
                rectangles[pairs[i].second].set_Y((x1 > x2 ? x1 : x2));
            }
        }
        ret = PARAMETER * area + (1 - PARAMETER) * wire;
    }
    kill();
    return ret;
}

Content *CornerBlockList::RandomChange(const Content *c) {
    Content *ret = new Content(c);
    int x = std::rand() % 4;
    if (x == 0) {
        int R1 = std::rand() % block_num;
        int R2 = std::rand() % block_num;

        while (R2 == R1)
            R2 = std::rand() % block_num;

        //Swap id
        ret->block_ids[R1] = ret->block_ids[R1] + ret->block_ids[R2];
        ret->block_ids[R2] = ret->block_ids[R1] - ret->block_ids[R2];
        ret->block_ids[R1] = ret->block_ids[R1] - ret->block_ids[R2];

    } else if (x == 1) {
        int P = std::rand() % (block_num - 1);
        ret->orientations[P] = !ret->orientations[P];
    } else if (x == 2) {
        int P = std::rand() % block_num;
        ret->ifrotate[P] = !ret->ifrotate[P];
    } else {
        int state = (std::rand() % 2) | (ret->uncover_rec_num.size() == block_num - 1);

        if (state) {
            (ret->uncover_rec_num).insert((ret->uncover_rec_num).begin() + std::rand() % (ret->uncover_rec_num.size()),
                                          true);
        } else {
            int p = std::rand() % (ret->uncover_rec_num.size() - block_num + 1) + 1;

            for (std::vector<bool>::iterator i = (ret->uncover_rec_num).begin(); i != (ret->uncover_rec_num).end(); i++)
                if ((*i)) {
                    p--;
                    if (!p) {
                        ret->uncover_rec_num.erase(i);
                        break;
                    }
                }
        }
    }
    return ret;
}
