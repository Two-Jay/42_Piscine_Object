#ifndef __TESTKIT_PISCINE_OBJECT_00_EX_00_HPP__
#define __TESTKIT_PISCINE_OBJECT_00_EX_00_HPP__

#include "Account.hpp"
#include "AccountManager.hpp"
#include "ANSI_Pont.hpp"

namespace test_kit {
    void isTruePass(bool condition, std::string name) {
        if (condition == false) {
            std::cout << "<<<<  [ test \'" << name << "\' PASSED] >>>> " << std::endl;
            exit(1);
        }
    }

    void printPassInformPrint(std::string name) {
        std::cout << GRNB << " [ test \'" << name << "\' PASSED] " << reset << std::endl;
    }
}

namespace ex00_testfield {
    void account_test() {
        std::string testcase_name = "account_test";
        Account acc1 = Account();
        Account acc2 = Account();
        
        test_kit::isTruePass((acc1.getValue() == 0), testcase_name);
        test_kit::isTruePass((acc2.getValue() == 0), testcase_name);
        test_kit::printPassInformPrint(testcase_name);
    }
}


#endif // __TESTKIT_PISCINE_OBJECT_00_EX_00_HPP__