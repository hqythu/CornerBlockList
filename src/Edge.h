#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge {
private:
    double length;
    Node *s;
    Node *t;
public:
    Edge() { }

    Edge(double len) : s(nullptr), t(nullptr), length(len) { }

    void set_len(double x) { length = x; }

    void set_s(Node *x) { s = x; }

    void set_t(Node *x) { t = x; }

    Node *get_s() const { return s; }

    Node *get_t() const { return t; }

    double get_len() const { return length; }
};

#endif // EDGE_H