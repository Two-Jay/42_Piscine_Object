#ifndef __ACCOUNT_MANAGER_HPP__
#define __ACCOUNT_MANAGER_HPP__

#include <iostream>
#include <vector>
#include "Account.hpp"

class Account;

class AccountManager {
    private :
        std::vector<Account *> clientAccounts;
        std::vector<bool> deletedAccountFlags;
        size_t accountsSize;

    public :
        AccountManager();
        ~AccountManager();

        void addAccount(Account *account);
        void removeAccount(Account *account);
        Account *searchAccount(Account *account) const;
        Account *searchAccount(int id) const;

        size_t getAccountsSize(void) const;
        size_t getAccountCapacity(void) const;

        
};


std::ostream &operator<<(std::ostream &os, const AccountManager &ref);



#endif