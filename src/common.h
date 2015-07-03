//
// Created by ZhuangTianYi on 15/6/22.
//

#ifndef CORNERBLOCKLIST_COMMON_H
#define CORNERBLOCKLIST_COMMON_H
#include <string>

const std::string FILE_NAME_PREFIX = "../test/data_in_";
const std::string FILE_NAME_SUFFIX = ".txt";

const int TEST_FILE_NUM = 1;

const int RECTANGLE_NUM = 50;

const int RECTANGLE_WIDTH_MAX = 30;
const int RECTANGLE_WIDTH_MIN = 10;

const int RECTANGLE_HEIGHT_MAX = 30;
const int RECTANGLE_HEIGHT_MIN = 10;

const int PAIR_NUM = RECTANGLE_NUM / 2;

const int SCREEN_WIDTH = 500;

// a parameter between 0 and 1 to decide the optimization
const double PARAMETER = 1;
const double INI_TEMP = 1000;
const double GOAL_TEMP = 10;
const int START_NUM = RECTANGLE_NUM * 2;
const double DEC = 0.95;
const double INC = 1.05;
#endif //CORNERBLOCKLIST_COMMON_H
