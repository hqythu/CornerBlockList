#include <iostream>
#include "TestCaseGenerator.h"
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    test::TestCaseGenerator* generator = test::TestCaseGenerator::Instance();

    generator -> generate(5);


    delete generator;
    return 0;
}