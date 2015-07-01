//
// Created by ZhuangTianYi on 15/7/1.
//

#ifndef CORNERBLOCKLIST_VISUALIZER_H
#define CORNERBLOCKLIST_VISUALIZER_H

#include "Rectangle.h"


class Visualizer {
private:
    double height, width;
    double center_x, center_y;
public:
    Visualizer(double h, double w) : height(h), width(w) { }

    void show(const std::vector<Rectangle> &rects);
};


#endif //CORNERBLOCKLIST_VISUALIZER_H
