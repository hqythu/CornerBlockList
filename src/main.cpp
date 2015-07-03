#include <iostream>
#include "common.h"
#include "TestCaseGenerator.h"
#include "CornerBlockList.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    test::TestCaseGenerator *generator = test::TestCaseGenerator::Instance();

    generator->generate(TEST_FILE_NUM);
    delete generator;

    vector<CornerBlockList> cbls;
    for (int i = 0; i < TEST_FILE_NUM; i++)
        cbls.push_back(CornerBlockList(FILE_NAME_PREFIX + char(i + '0') + FILE_NAME_SUFFIX));
    for (int i = 0; i < TEST_FILE_NUM; i++)
        cbls[i].optimize();
    for (auto cbl = cbls.begin(); cbl != cbls.end(); cbl++)
        cbl->show();

    return 0;
}