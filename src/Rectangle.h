//
// Created by ZhuangTianYi on 15/6/21.
//

#ifndef CORNERBLOCKLIST_RECTANGLE_H
#define CORNERBLOCKLIST_RECTANGLE_H

#include "Edge.h"
#include "Node.h"

class Rectangle {
private:
    double center_x;
    double center_y;
    double width;
    double height;
    Edge *V_edge;
    Edge *H_edge;
public:
    Rectangle() { }

    Rectangle(double w, double h) : center_x(0), center_y(0), width(w), height(h) {
        V_edge = new Edge(width);
        H_edge = new Edge(height);
    }

    double CENTER_X() const { return center_x; }

    double CENTER_Y() const { return center_y; }

    double GET_WIDTH(bool s) const { return (s ? height : width); }

    double GET_HEIGHT(bool s) const { return (s ? width : height); }

    Edge *GET_V() { return V_edge; }

    Edge *GET_H() { return H_edge; }

    void SET_X(double x) { center_x = x; }

    void SET_Y(double y) { center_y = y; }
};

#endif //CORNERBLOCKLIST_SQUARE_H
