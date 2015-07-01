#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge {
private:
    Node *s;
    Node *t;
    double length;
public:
    Edge() { }

    Edge(double len) : s(nullptr), t(nullptr), length(len) { }

    void SetLen(double x) { length = x; }

    void SetS(Node *x) { s = x; }

    void SetT(Node *x) { t = x; }

    Node *GET_S() { return s; }

    Node *GET_T() { return t; }

    double GET_LEN() { return length; }
};

#endif