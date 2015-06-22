//
// Created by ZhuangTianYi on 15/6/21.
//

#ifndef CORNERBLOCKLIST_RECTANGLE_H
#define CORNERBLOCKLIST_RECTANGLE_H

struct Rectangle {
    int id;

    int center_x;
    int center_y;
    int width;
    int height;
    Rectangle() {}
    Rectangle(int i, int w, int h) : id(i), center_x(0), center_y(0), width(w), height(h) {}
};

#endif //CORNERBLOCKLIST_SQUARE_H
