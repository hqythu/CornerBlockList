//
// Created by ZhuangTianYi on 15/6/21.
//

#ifndef CORNERBLOCKLIST_CORDERBLOCKLIST_H
#define CORNERBLOCKLIST_CORDERBLOCKLIST_H

#include "common.h"
#include "Rectangle.h"
#include <vector>
#include <string>
#include <utility>
#include "Node.h"
#include "State.h"

class CornerBlockList {
    std::vector<Rectangle> rectangles;
    State *state;
    // Two stacks used in show()
    std::vector<int> HStack;
    std::vector<int> VStack;

    // pairs
    std::vector<std::pair<int, int> > pairs;
    std::vector<Node *> nd_list;
    int block_num, pair_num;
    Node *E;
    Node *N;
    Node *W;
    Node *S;

    State *RandomChange(const State *c);

    bool build(const State *c);

    void cal_longest(Node *start);

    void kill();

public:
    CornerBlockList();

    CornerBlockList(const std::string &file_name);

    // show the CBL in GUI
    void show();

    void optimize();

    // Considering both the weighted sum of the area
    // and the total Manhattan wirelength with a
    // parameter between 0 and 1.
    double evaluate(const State *c);
};


#endif //CORNERBLOCKLIST_CORDERBLOCKLIST_H
