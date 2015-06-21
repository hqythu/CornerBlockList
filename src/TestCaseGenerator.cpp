//
// Created by ZhuangTianYi on 15/6/21.
//

#include "TestCaseGenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>


namespace test {

    const int RECTANGLE_NUM_MAX = 500;
    const int RECTANGLE_NUM_MIN = 300;

    const int RECTANGLE_WIDTH_MAX = 30;
    const int RECTANGLE_WIDTH_MIN = 10;

    const int RECTANGLE_HEIGHT_MAX = 30;
    const int RECTANGLE_HEIGHT_MIN = 10;

    TestCaseGenerator* TestCaseGenerator::generator_ = 0;

    TestCaseGenerator* TestCaseGenerator::Instance() {
        if (generator_ == 0)
            generator_ = new TestCaseGenerator();
        return generator_;
    }

    void TestCaseGenerator::generate(int cnt) {
        std::srand((unsigned int)time(NULL));
        std::ofstream fout;

        for (int i = 0; i < cnt; i++) {
            std::string file_name = "../test/data_in_" + std::to_string(i) + ".txt";

            fout.open(file_name, std::ios::out | std::ios::trunc | std::ios::binary);

            int n = RECTANGLE_NUM_MIN + std::rand() % (RECTANGLE_NUM_MAX - RECTANGLE_NUM_MIN);

            if (fout.is_open()) {
                std::clog << "Writing data_in_" << i << ".txt" << std::endl;
                for (int j = 0; j < n; j++) {
                    int width = RECTANGLE_WIDTH_MIN     + std::rand() % (RECTANGLE_WIDTH_MAX - RECTANGLE_WIDTH_MIN);
                    int height = RECTANGLE_HEIGHT_MIN + std::rand() % (RECTANGLE_HEIGHT_MAX - RECTANGLE_WIDTH_MIN);
                    fout << width << ' ' << height << std::endl;
                }
            }
            else {
                std::cerr << "ERROR: FILE NOT OPEN!" << std::endl;
                exit(-1);
            }

            fout.close();
        }
    }
}