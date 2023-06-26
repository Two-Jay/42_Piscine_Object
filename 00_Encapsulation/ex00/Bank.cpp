#include "Bank.hpp"

#include "Account.hpp"
#include "AccountManager.hpp"
#include "AccountFeeManager.hpp"

#define BANK_LIQUIDITY_DEFAULT_VALUE 0;

Bank::Bank() {
    this->accountManager = AccountManager();
    this->accountFeeManager = AccountFeeManager();
    this->liquidity = BANK_LIQUIDITY_DEFAULT_VALUE;
}

Bank::Bank(int liquidity) {
    this->accountManager = AccountManager();
    this->accountFeeManager = AccountFeeManager();
    this->liquidity = liquidity;
}

Bank::~Bank() {}

void Bank::addAccount(Account *account) {
    try {
        this->accountManager.addAccount(account);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Bank::removeAccount(Account *account) {
    try {
        this->accountManager.removeAccount(account);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}

Account *Bank::findAccountById(unsigned int id) {
    Account *ac = this->accountManager.searchAccount(id);
    return this->accountManager.isAlive(ac) ? ac : NULL;
}

int Bank::getLiquidity() const {
    return this->liquidity;
}

const AccountManager &Bank::getAccountManager() const {
    return this->accountManager;
}

std::ostream &operator<<(std::ostream &os, const Bank &ref) {
    os << "Bank --------------------" << std::endl;
    os << " - liquidity : " << ref.getLiquidity() << std::endl;
    os << ref.getAccountManager();
    return os;
}