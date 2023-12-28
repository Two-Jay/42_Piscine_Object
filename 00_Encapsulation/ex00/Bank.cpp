#include "Bank.hpp"
#include <stdexcept>

int Bank::_AccountIDCounts = 0;
float Bank::_interestRate = 0.05f;

Bank::Bank() : _liquidity(0) {}

Bank::Bank(int liquidity) : _liquidity(liquidity) {}

Bank::~Bank() {}

int Bank::getLiquidity() const {
    return _liquidity;
}

void Bank::setLiquidity(int liquidity) {
    if (liquidity < 0)
        throw std::runtime_error(ERRMSG("Liquidity cannot be negative"));
    _liquidity = liquidity;
}

void Bank::addLiquidity(int liquidity) throw(std::exception) {
    _liquidity += liquidity;
}

int Bank::makeAccount() throw(std::exception) {
    Account account = createNewAccount();
    _clientAccounts.insert(std::pair<int, Account>(account.getId(), account));
    return (account.getId());
}

int Bank::closeAccount(int id) throw(std::exception) {
    std::map<int, Account>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
        throw std::runtime_error(ERRMSG("Account not found"));
    _clientAccounts.erase(it);
    return (id);
}

void Bank::deposit(int id, int value) throw(std::exception) {
    std::map<int, Account>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
        throw std::runtime_error(ERRMSG("Account not found"));
    int interest_value = value * _interestRate;
    int deposit_value = value - interest_value;
    this->addLiquidity(interest_value);
    it->second._value += deposit_value;
}

void Bank::withdraw(int id, int value) throw(std::exception) {
    std::map<int, Account>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
        throw std::runtime_error(ERRMSG("Account not found"));
    it->second._value -= value;
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank) {
    p_os << "Bank informations ------- " << std::endl;
    p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
    if (p_bank._clientAccounts.empty() == true) {
        p_os << "No account" << std::endl;
    } else {
        for (std::map<int, Bank::Account>::const_iterator it = p_bank._clientAccounts.begin(); it != p_bank._clientAccounts.end(); it++) {
            p_os << it->second;
        }
    }
    return (p_os);
}

void Bank::showLoanRecords(int id) throw(std::exception) {
    std::map<int, std::vector<LoanRecord> >::iterator it = _loanRecords.find(id);
    if (it == _loanRecords.end())
        throw std::runtime_error(ERRMSG("Account not found"));
    std::vector<LoanRecord> loanRecords = it->second;
    if (loanRecords.empty() == true) {
        std::cout << NOTIMSG("No loan record in this account.") << std::endl;
    } else {
        for (std::vector<LoanRecord>::iterator it = loanRecords.begin(); it != loanRecords.end(); it++) {
            std::cout << *it;
        }
    }
}

void Bank::takeLoan(int id, int value, int duration) throw(std::exception) {
    std::map<int, Account>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
        throw std::runtime_error(ERRMSG("Account not found"));
    if (value <= 0)
        throw std::runtime_error(ERRMSG("Loan value cannot be zero or negative"));
    if (duration <= 0)
        throw std::runtime_error(ERRMSG("Loan duration cannot be zero or negative"));
    LoanRecord loanRecord = this->createNewLoanRecord(id, value, duration);
    this->addLoanRecordHistory(loanRecord);
    it->second._value += value;
    this->addLiquidity(-value);
}

void Bank::repayLoan(int id, int value) throw(std::exception) {
    if (value < 0)
        throw std::runtime_error(ERRMSG("Loan value cannot be negative"));
    std::map<int, Account>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end())
        throw std::runtime_error(ERRMSG("Account not found"));
    std::map<int, std::vector<LoanRecord> >::iterator it2 = _loanRecords.find(id);
    if (it2 == _loanRecords.end())
        throw std::runtime_error(ERRMSG("There is NO loan record by id"));
    LoanRecord &oldestLoanRecord = it2->second.front();
    Account &account = it->second;
    if (account._value < value)
        throw std::runtime_error(ERRMSG("Not enough money to repay"));
    if (oldestLoanRecord._value <= value) {
        account._value -= oldestLoanRecord._value;
        this->addLiquidity(oldestLoanRecord._value);
        it2->second.erase(it2->second.begin());
        if (it2->second.empty() == true) {
            _loanRecords.erase(it2);
            std::cout << NOTIMSG("all loan records are repaid") << std::endl;
        }    
    } else {
        oldestLoanRecord._value -= value;
        account._value -= value;
        this->addLiquidity(value);
    }
}