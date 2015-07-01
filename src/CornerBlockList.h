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
#include "Content.h"

class CornerBlockList {
    std::vector<Rectangle> rectangles;
    Content* con;
    // Two stacks used in show()
    std::vector<int> HStack;
    std::vector<int> VStack;

    // pairs
    std::vector< std::pair<int, int> > pairs;
    
    int block_num,pair_num;
    Node* E;
    Node* N;
    Node* W;
    Node* S;
    Content* RandomChange(const Content* c);
    bool build(const Content* c);
    void cal_longest(Node* start);
    void kill();
public:
    CornerBlockList();
    CornerBlockList(const std::string& file_name);

    // show the CBL in GUI
    void show();

    // TODO: using Simulated Annealing Algorithm to optimize the CBL
    void optimize();

    // TODO: A function used in optimize().
    // Considering both the weighted sum of the area
    // and the total Manhattan wirelength with a
    // parameter between 0 and 1.
    double assess(const Content* c);
};


#endif //CORNERBLOCKLIST_CORDERBLOCKLIST_H
