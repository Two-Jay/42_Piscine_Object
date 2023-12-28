
#include "Bank.hpp"

int Bank::Account::getId() const {
    return _id;
}

int Bank::Account::getValue() const {
    return _value;
}

Bank::Account Bank::createNewAccount(void) {
    Account account = Account();
    account._id = _AccountIDCounts;
    _AccountIDCounts++;
    return (account);
}

Bank::Account &Bank::operator[](int id) throw(std::exception) {
    std::map<int, Account>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
        throw std::runtime_error(ERRMSG("Account not found"));
    return (it->second);
}

std::ostream &operator<<(std::ostream &p_os, const Bank::Account &p_account) {
    p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]" << std::endl;
    return (p_os);
}