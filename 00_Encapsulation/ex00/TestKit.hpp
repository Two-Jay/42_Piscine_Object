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
        test_kit::printPassInformPrint("account_test");
    }
}


#endif // __TESTKIT_PISCINE_OBJECT_00_EX_00_HPP__