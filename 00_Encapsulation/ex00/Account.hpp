#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <iostream>
#include "AccountManager.hpp"

class Account {
    private :
        static unsigned int ACCOUNT_ID_INDEX;

        unsigned int id;
        unsigned int value;
        friend bool AccountManager::addValueToAccount(Account *ac, unsigned int value);
        friend bool AccountManager::subValueInAccount(Account *ac, unsigned int value);

    public :
        Account();
        Account(const Account &origin);
        Account &operator=(const Account &ref);

        unsigned int getValue(void) const;
        unsigned int getId(void) const;


};



std::ostream &operator<<(std::ostream &os, const Account &ref);

#endif