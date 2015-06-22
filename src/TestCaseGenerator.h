//
// Created by ZhuangTianYi on 15/6/21.
//

#ifndef CORNERBLOCKLIST_TESTCASEGENERATOR_H
#define CORNERBLOCKLIST_TESTCASEGENERATOR_H

namespace test {

class TestCaseGenerator {
private:
    static TestCaseGenerator* generator_;
    TestCaseGenerator() {};
    TestCaseGenerator(TestCaseGenerator&) {};
    TestCaseGenerator* operator = (TestCaseGenerator) { return generator_; }
public:
    static TestCaseGenerator* Instance();
    void generate(int cnt);
};

}  // test


#endif //CORNERBLOCKLIST_TESTCASEGENERATOR_H
