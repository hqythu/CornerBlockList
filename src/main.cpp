#include <iostream>
#include "common.h"
#include "TestCaseGenerator.h"
#include "CornerBlockList.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    test::TestCaseGenerator* generator = test::TestCaseGenerator::Instance();

    generator -> generate(TEST_FILE_NUM);

    vector <CornerBlockList> cbls;
    for (int i = 0; i < TEST_FILE_NUM; i++) {
        cbls.push_back(CornerBlockList(FILE_NAME_PREFIX + std::to_string(i) + FILE_NAME_SUFFIX));
    }

    for (auto cbl : cbls)
        cbl.show();

    delete generator;
    return 0;
}