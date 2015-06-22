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
bool pred(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return !((p1.first != p1.second) &&
             (p2.first != p2.second) &&
             ((p1.first != p2.first) || (p1.second != p2.second)) &&
             ((p1.first != p2.second) || (p1.second != p2.first)));
}

namespace test {

    TestCaseGenerator* TestCaseGenerator::generator_ = nullptr;

    TestCaseGenerator* TestCaseGenerator::Instance() {
        if (generator_ == 0)
            generator_ = new TestCaseGenerator();
        return generator_;
    }

    void TestCaseGenerator::generate(int cnt) {
        std::srand((unsigned int)std::time(nullptr));
        std::ofstream fout;

        for (int i = 0; i < cnt; i++) {
            // open file
            std::string file_name = "../test/data_in_" + std::to_string(i) + ".txt";
            fout.open(file_name, std::ios::out | std::ios::trunc | std::ios::binary);

            int n = RECTANGLE_NUM_MIN + std::rand() % (RECTANGLE_NUM_MAX - RECTANGLE_NUM_MIN);

            if (fout.is_open()) {
                // write random rectangles' number
                fout << n << std::endl;

                // write random rectangles parameters
                std::clog << "Writing data_in_" << i << ".txt" << std::endl;
                for (int j = 0; j < n; j++) {
                    int width = RECTANGLE_WIDTH_MIN     + std::rand() % (RECTANGLE_WIDTH_MAX - RECTANGLE_WIDTH_MIN);
                    int height = RECTANGLE_HEIGHT_MIN + std::rand() % (RECTANGLE_HEIGHT_MAX - RECTANGLE_WIDTH_MIN);
                    fout << width << ' ' << height << std::endl;
                }

                // rectangle  ending tag
                fout << "0 0" << std::endl;

                // make random pairs
                // TODO: The random pairs generator may has a better implementation

                std::vector < std::pair<int, int> > pairs;

                // make double pairs to ensure enough unique pairs.
                for (int j = 0; j < 2 * PAIR_NUM; j++)
                    pairs.push_back(std::make_pair(std::rand() % n + 1, std::rand() % n + 1));

                // unique
                pairs.erase(std::unique(pairs.begin(), pairs.end(), pred), pairs.end());

                // print
                int count = 0;
                while (count++ < PAIR_NUM)
                    fout << pairs[count].first << ' ' << pairs[count].second << std::endl;
            }
            else {
                std::cerr << "ERROR: FILE NOT OPEN!" << std::endl;
                exit(-1);
            }

            // close
            fout.close();
        }
    }
}