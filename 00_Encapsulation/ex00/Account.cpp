#include "Account.hpp"

#define ACCOUNT_DEFAULT_VALUE 0

unsigned int Account::ACCOUNT_ID_INDEX = -1;

int Account::initialize_account_id() {
    return ++Account::ACCOUNT_ID_INDEX;
}

Account::Account() {
    this->id = initialize_account_id();
    this->value = ACCOUNT_DEFAULT_VALUE;
}

Account::Account(int value) {
    this->id = initialize_account_id();
    this->value = value;
}

Account::Account(const Account &origin) {
    this->id = origin.getId();
    this->value = origin.getValue();
}

Account::~Account() {}

unsigned int Account::getValue(void) const {
    return this->value;
}

unsigned int Account::getId(void) const {
    return this->id;
}

Account &Account::operator=(const Account &ref) {
    if (this != &ref) {
        this->id = ref.getId();
        this->value = ref.getValue();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Account &ref) {
    return os << "[" << ref.getId() << "] - [" << ref.getValue() << "]";
}