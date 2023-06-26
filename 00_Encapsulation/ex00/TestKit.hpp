#ifndef __TESTKIT_PISCINE_OBJECT_00_EX_00_HPP__
#define __TESTKIT_PISCINE_OBJECT_00_EX_00_HPP__

#include "Account.hpp"
#include "AccountManager.hpp"
#include "ANSI_Pont.hpp"

namespace test_kit {
    void isTruePass(bool condition, const std::string &name) {
        if (condition == false) {
            std::cout << "<<<<  [ test \'" << name << "\' PASSED] >>>> " << std::endl;
            exit(1);
        }
    }

    void printPassInformPrint(const std::string &name) {
        std::cout << GRNB << " [ test \'" << name << "\' PASSED] " << reset << std::endl;
    }
}

namespace ex00_testfield {
    void testAccount() {
        Account acc1 = Account();
        Account acc2 = Account();
        
        test_kit::isTruePass((acc1.getValue() == 0), __PRETTY_FUNCTION__);
        test_kit::isTruePass((acc2.getValue() == 0), __PRETTY_FUNCTION__);
        test_kit::printPassInformPrint(__PRETTY_FUNCTION__);
    }

    void testAccountManager_00() {
        Account acc1 = Account();
        Account acc2 = Account();
        test_kit::isTruePass((acc1.getValue() == 0), __PRETTY_FUNCTION__);
        test_kit::isTruePass((acc2.getValue() == 0), __PRETTY_FUNCTION__);


        AccountManager manager = AccountManager();
        test_kit::isTruePass((manager.size() == 0), __PRETTY_FUNCTION__);

        manager.addAccount(&acc1);
        manager.addAccount(&acc2);
        test_kit::isTruePass((manager.size() == 2), __PRETTY_FUNCTION__);

        manager.removeAccount(&acc1);
        test_kit::isTruePass((manager.size() == 1), __PRETTY_FUNCTION__);
        
        test_kit::printPassInformPrint(__PRETTY_FUNCTION__);
    }

    void testAccountManager_01() {
        Account acc1 = Account();
        test_kit::isTruePass((acc1.getValue() == 0), __PRETTY_FUNCTION__);

        AccountManager manager = AccountManager();
        test_kit::isTruePass((manager.size() == 0), __PRETTY_FUNCTION__);

        manager.addAccount(&acc1);
        test_kit::isTruePass((manager.size() == 1), __PRETTY_FUNCTION__);

        manager.addValueToAccount(&acc1, 4242);
        test_kit::isTruePass((acc1.getValue() == 4242), __PRETTY_FUNCTION__);

        manager.subValueInAccount(&acc1, 1000);
        test_kit::isTruePass((acc1.getValue() == 3242), __PRETTY_FUNCTION__);

        test_kit::printPassInformPrint(__PRETTY_FUNCTION__);
    }

    void testAccountManager_bundle() {
        testAccountManager_00();
        testAccountManager_01();
    }

    void testAccountManager() {
        testAccountManager_bundle();
    }
}

#endif // __TESTKIT_PISCINE_OBJECT_00_EX_00_HPP__