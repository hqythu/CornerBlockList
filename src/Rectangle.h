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
    Rectangle() {}
    Rectangle(double w, double h) : center_x(0), center_y(0), width(w), height(h) {
      V_edge = new Edge(width);
      H_edge = new Edge(height);
    }
    double get_center_x() const { return center_x; }
    double get_center_y() const { return center_y; }
    double get_width(bool s) const { return (s?height:width); }
    double get_height(bool s) const { return (s?width:height); }
    Edge* get_v() const { return V_edge; }
    Edge* get_h() const { return H_edge;  }
    void set_x(double x) { center_x = x; }
    void set_y(double y) { center_y = y; }
};

#endif //CORNERBLOCKLIST_SQUARE_H
