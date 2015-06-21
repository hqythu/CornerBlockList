//
// Created by ZhuangTianYi on 15/6/21.
//

#ifndef CORNERBLOCKLIST_CORDERBLOCKLIST_H
#define CORNERBLOCKLIST_CORDERBLOCKLIST_H
#include "Rectangle.h"
#include <vector>

class CornerBlockList {
    std::vector<Rectangle> squres;

    // Mr. Yao uses letter to present every block and
    // I think block id will be better.
    std::vector<int> block_id;

    // 0 for horizontal and 1 for vertical
    std::vector<bool> orientation;

    // 0 presents 1 and 10 presents 2, details in PPT
    std::vector<bool> uncover_rec_num;

    // Two stacks used in show()
    std::vector<int> HStack;
    std::vector<int> VStack;

public:
    CornerBlockList();

    // TODO: show the CBL in GUI
    void show();

    // TODO: using Simulated Annealing Algorithm to optimize the CBL
    void optimize();

    // TODO: A function used in optimize().
    // Considering both the weighted sum of the area
    // and the total Manhattan wirelength with a
    // parameter between 0 and 1.
    void Assess(double parameter);

};


#endif //CORNERBLOCKLIST_CORDERBLOCKLIST_H
