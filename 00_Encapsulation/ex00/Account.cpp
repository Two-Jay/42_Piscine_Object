#include "Account.hpp"

unsigned int Account::ACCOUNT_ID_INDEX = -1;
unsigned int Account::ACCOUNT_DEFAULT_VALUE = 0;

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
    this->setId(origin.getId());
    this->setValue(origin.getValue());
}

Account::~Account() {}

unsigned int Account::getValue(void) const {
    return this->value;
}

unsigned int Account::getId(void) const {
    return this->id;
}

void Account::setId(unsigned int id) {
    this->id = id;
}

void Account::setValue(unsigned int value) {
    this->value = value;
}

Account &Account::operator=(const Account &ref) {
    if (this != &ref) {
        this->setId(ref.getId());
        this->setValue(ref.getValue());
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Account &ref) {
    return os << "[" << ref.getId() << "] - [" << ref.getValue() << "]";
}