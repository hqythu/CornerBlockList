//
// Created by ZhuangTianYi on 15/6/21.
//

#include "TestCaseGenerator.h"
#include "common.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// a function for check pairs
bool pred(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return !((p1.first != p1.second) &&
             (p2.first != p2.second) &&
             ((p1.first != p2.first) || (p1.second != p2.second)) &&
             ((p1.first != p2.second) || (p1.second != p2.first)));
}

namespace test {

TestCaseGenerator *TestCaseGenerator::generator_ = NULL;

TestCaseGenerator *TestCaseGenerator::Instance() {
    if (generator_ == 0)
        generator_ = new TestCaseGenerator();
    return generator_;
}

void TestCaseGenerator::generate(int cnt) {
    std::srand((unsigned int) std::time(NULL));
    std::ofstream fout;

    for (int i = 0; i < cnt; i++) {
        // open file
        std::string file_name = FILE_NAME_PREFIX + char(i+'0') + FILE_NAME_SUFFIX;
        fout.open(file_name.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);

        int n = RECTANGLE_NUM;

        if (fout.is_open()) {
            // write random rectangles' number
            fout << n << std::endl;
			
            // write random rectangles parameters
            std::clog << "Writing data_in_" << i << ".txt" << std::endl;
            for (int j = 0; j < n; j++) {
                int width = RECTANGLE_WIDTH_MIN + std::rand() % (RECTANGLE_WIDTH_MAX - RECTANGLE_WIDTH_MIN);
                int height = RECTANGLE_HEIGHT_MIN + std::rand() % (RECTANGLE_HEIGHT_MAX - RECTANGLE_WIDTH_MIN);
                fout << width << ' ' << height << std::endl;
            }

            // rectangle  ending tag
            fout << "0 0" << std::endl;

            // make random pairs
            // TODO: The random pairs generator may has a better implementation

            std::vector<std::pair<int, int> > pairs;

            int pair[RECTANGLE_NUM];
            for (int i = 0;i < RECTANGLE_NUM;i++)
                pair[i] = i + 1;
            std::random_shuffle(pair,pair+RECTANGLE_NUM);
            
            // print
            fout << PAIR_NUM << std::endl;
            for (int i = 1;i <= PAIR_NUM;i++)
                fout << pair[2*i-2] << " " << pair[2*i-1] << std::endl;
        }
        else {
            std::cerr << "ERROR: FILE NOT OPEN!" << std::endl;
            exit(-1);
        }
        // close
        fout.close();
    }
}


}  //test

