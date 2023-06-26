#include "AccountManager.hpp"

#define ACCOUNTS_VECTOR_DEFAULT_SIZE 20

AccountManager::AccountManager() {
    this->clientAccounts = std::vector<Account *>(ACCOUNTS_VECTOR_DEFAULT_SIZE, NULL);
    this->accountsSize = 0;
}

AccountManager::~AccountManager() {
}

void AccountManager::addAccount(Account *account) {
    this->clientAccounts[account->getId()] = account;
    this->accountsSize++;
}

void AccountManager::removeAccount(Account *account) {
    this->clientAccounts[account->getId()] = NULL;
    this->accountsSize--;
}

Account *AccountManager::searchAccount(Account *account) const {
    return this->clientAccounts[account->getId()];
}

Account *AccountManager::searchAccount(int id) const {
    return this->clientAccounts[id];
}

size_t AccountManager::getAccountsSize(void) const {
    return this->accountsSize;
}

size_t AccountManager::getAccountCapacity(void) const {
    return this->clientAccounts.size();
}

// bool addValuetoAccount(Account *account, unsigned int value) {
//     if (!account) return false;
//     account->value += value;
//     return true;
// }

// bool AccountManager::addValuetoAccount(int accountId, unsigned int value) {
//     Account *account = searchAccount(accountId);
//     if (!account) return false;
//     account->value += value;
//     return true;
// }

// bool AccountManager::subValuetoAccount(Account *account, unsigned int value) {
//     if (!account) return false;
//     account->value -= value;
//     return true;
// }

// bool AccountManager::subValuetoAccount(int accountId, unsigned int value) {
//     Account *account = searchAccount(accountId);
//     if (!account) return false;
//     account->value -= value;
//     return true;
// }

std::ostream &operator<<(std::ostream &os, const AccountManager &ref) {
    os << "AccountManager size : " << ref.getAccountsSize() << std::endl;

    for (size_t i = 0; i < ref.getAccountCapacity(); i++) {
        int accountIndex = static_cast<int>(i);
        Account *account = ref.searchAccount(accountIndex);
        if (account != NULL) {
            os << *account << std::endl;
        }
    }
    return os;
}
