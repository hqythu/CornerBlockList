//
// Created by ZhuangTianYi on 15/7/1.
//

#ifndef CORNERBLOCKLIST_VISUALIZER_H
#define CORNERBLOCKLIST_VISUALIZER_H

#include "Rectangle.h"
#include "CornerBlockList.h"


class Visualizer {
public:
    void show(const std::vector<Rectangle> &rectangles, State *state) const;
};


#endif //CORNERBLOCKLIST_VISUALIZER_H
