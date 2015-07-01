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

    generator -> generate(TEST_FILE_NUM);

    delete generator;

    vector <CornerBlockList> cbls;

    for (auto cbl : cbls) {
        cbl.optimize();
        cbl.show();
    }

    return 0;
}