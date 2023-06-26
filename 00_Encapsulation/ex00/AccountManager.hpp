#ifndef __ACCOUNT_MANAGER_HPP__
#define __ACCOUNT_MANAGER_HPP__

#include <iostream>
#include <vector>

class Account;

class AccountManager {
    private :
        std::vector<Account *> clientAccounts;
        size_t AccountsSize;

    public :
        AccountManager();
        ~AccountManager();

        void addAccount(Account *account);
        void removeAccount(Account *account);
        Account *searchAccount(Account *account) const;
        Account *searchAccount(int id) const;

        bool isAlive(Account *ac) const;
        size_t size() const;
        size_t capacity() const;

        bool addValueToAccount(Account *ac, unsigned int value);
        bool addValueToAccount(unsigned int id, unsigned int value);
        bool subValueInAccount(Account *ac, unsigned int value);
        bool subValueInAccount(unsigned int id, unsigned int value);
};

#include "Account.hpp"


std::ostream &operator<<(std::ostream &os, const AccountManager &ref);
void assertInvalidAccount(bool condition, std::string msg);

#endif