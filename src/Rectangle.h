//
// Created by ZhuangTianYi on 15/6/21.
//

#ifndef CORNERBLOCKLIST_RECTANGLE_H
#define CORNERBLOCKLIST_RECTANGLE_H

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
    Rectangle(double w, double h) : left_bottom_x(0), left_bottom_y(0), width(w), height(h) {
      V_edge = new Edge(width);
      H_edge = new Edge(height);
    }
    double CENTER_X() { return center_x; }
    double CENTER_Y() { return center_y; }  
    double GET_WIDTH(bool s) { return (s?height:width); }
    double GET_HEIGHT(bool s) { return (s?width:height); }
    Edge* GET_V() { return V_edge; }
    Edge* GET_H() { return H_edge;  }
    void SET_X(int x) { center_x = x; }
    void SET_Y(int y) { center_y = y; }
};

#endif //CORNERBLOCKLIST_SQUARE_H
