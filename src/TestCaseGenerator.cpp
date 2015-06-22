//
// Created by ZhuangTianYi on 15/6/21.
//

#include "TestCaseGenerator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


namespace test {

    const int RECTANGLE_NUM_MAX = 500;
    // WARNING: The implementation of random pair generator
    // has some bug so RECTANGLE_NUM_MIN should not be less
    // than PAIR_NUM;
    const int RECTANGLE_NUM_MIN = 300;

    const int RECTANGLE_WIDTH_MAX = 30;
    const int RECTANGLE_WIDTH_MIN = 10;

    const int RECTANGLE_HEIGHT_MAX = 30;
    const int RECTANGLE_HEIGHT_MIN = 10;

    const int PAIR_NUM = 250;

    TestCaseGenerator* TestCaseGenerator::generator_ = 0;

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
                // write random rectangles
                std::clog << "Writing data_in_" << i << ".txt" << std::endl;
                for (int j = 0; j < n; j++) {
                    int width = RECTANGLE_WIDTH_MIN     + std::rand() % (RECTANGLE_WIDTH_MAX - RECTANGLE_WIDTH_MIN);
                    int height = RECTANGLE_HEIGHT_MIN + std::rand() % (RECTANGLE_HEIGHT_MAX - RECTANGLE_WIDTH_MIN);
                    fout << width << ' ' << height << std::endl;
                }

                // rectangle ending tag
                fout << "0 0" << std::endl;

                // make random pairs
                // TODO: The random pairs generator may has a better implementation
                std::vector <int> rectangle_ids;
                for (int j = 1; j <= n; j++)
                    rectangle_ids.push_back(j);
                std::random_shuffle(rectangle_ids.begin(), rectangle_ids.end());
                for (int j = 0; j < PAIR_NUM; j++)
                    fout << rectangle_ids[j] << ' ' << rectangle_ids[j + 1] << std::endl;
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