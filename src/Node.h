#ifndef NODE_H
#define NODE_H

#include <vector>
#include "Edge.h"

class Edge;

struct Node {
    std::vector<Edge *> edges;
    double dis;
    int Go_in;

    Node() {
        dis = 0;
        Go_in = 0;
    }

    void Add(Edge *e) { edges.push_back(e); }
};

#endif