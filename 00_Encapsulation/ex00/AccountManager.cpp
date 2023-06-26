#include "AccountManager.hpp"

#define ACCOUNTS_VECTOR_DEFAULT_SIZE 20

AccountManager::AccountManager() {
    this->clientAccounts = std::vector<Account *>(ACCOUNTS_VECTOR_DEFAULT_SIZE, NULL);
    this->AccountsSize = 0;
}

AccountManager::~AccountManager() {
    // AccountManager가 소멸될 때
    // 내부에 있는 Account는 임의로 소멸하지 않기로 한다.
}

void AccountManager::addAccount(Account *account) {
    this->clientAccounts[account->getId()] = account;
    this->AccountsSize++;
}

void AccountManager::removeAccount(Account *account) {
    bool pop_flag = this->clientAccounts[account->getId()] != NULL ? true : false;
    this->clientAccounts[account->getId()] = NULL;
    if (pop_flag) this->AccountsSize--;
}

Account *AccountManager::searchAccount(Account *account) const {
    return this->clientAccounts[account->getId()];
}

Account *AccountManager::searchAccount(int id) const {
    return this->clientAccounts[id];
}

bool AccountManager::isAlive(Account *ac) const {
    return ac != NULL ? true : false;
}

bool AccountManager::addValueToAccount(Account *ac, unsigned int value) {
    if (this->isAlive(ac) == false) {
        return false;
    }
    ac->value += value;
    return true;
}

bool AccountManager::addValueToAccount(unsigned int id, unsigned int value) {
    Account *ac = this->searchAccount(id);
    return this->addValueToAccount(ac, value);
}

size_t AccountManager::size() const {
    return this->AccountsSize;
}

size_t AccountManager::capacity() const {
    return this->clientAccounts.capacity();
}

bool AccountManager::subValueInAccount(Account *ac, unsigned int value) {
    if (this->isAlive(ac) == false) {
        return false;
    }
    ac->value -= value;
    return true;
}

bool AccountManager::subValueInAccount(unsigned int id, unsigned int value) {
    Account *ac = this->searchAccount(id);
    return this->subValueInAccount(ac, value);
}

std::ostream &operator<<(std::ostream &os, const AccountManager &ref) {
    os << "AccountManager ---------------------" << std::endl;
    os << "- size : " << ref.size() << std::endl;
    for (size_t i = 0; i < ref.capacity(); i++) {
        Account *found = ref.searchAccount(i);
        if (ref.isAlive(found))
            os << *found << std::endl;
    }
    return os;
}