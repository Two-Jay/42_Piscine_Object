#include "Bank.hpp"

#include "Account.hpp"
#include "AccountManager.hpp"
#include "AccountFeeManager.hpp"

Bank::Bank() {
    this->accountManager = AccountManager();
    this->accountFeeManager = AccountFeeManager();
}

