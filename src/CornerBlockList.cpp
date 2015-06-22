//
// Created by ZhuangTianYi on 15/6/21.
//

#include "CornerBlockList.h"
#include <iostream>
#include <fstream>

CornerBlockList::CornerBlockList() {}

// TODO
CornerBlockList::CornerBlockList(const std::string& file_name) {
    std::ifstream fin;
    fin.open(file_name);

    if (!fin.is_open())
        std::cerr << "ERROR: FILE NOT OPEN" << std::endl;

    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        if (fin.eof()) {
            std::cerr << "ERROR: FILE ENDING!" << std::endl;
            break;
        }

        int width, height;
        fin >> width >> height;
        rectangles.push_back(Rectangle(i + 1, width, height));
    }

    // check rectangle read ending
    {
        int tmp1, tmp2;
        fin >> tmp1 >> tmp2;
        if (tmp1 != 0 || tmp2 != 0)
            std::cerr << "ERRPR: input data error.";
    }

    for (int i = 0; i < n; i++) {
        int rec1_id, rec2_id;
        fin >> rec1_id >> rec2_id;
        pairs.push_back(std::make_pair(rec1_id, rec2_id));
    }

    fin.close();
}

void CornerBlockList::show() {
    // for debug
    for (auto rectangle : rectangles) {
        std::cout << rectangle.width << ' ' << rectangle.height << std::endl;
    }

    for (auto pair : pairs) {
        std::cout << pair.first << ' ' << pair.second << std::endl;
    }
}

void optimize() {

}

void assess() {

}