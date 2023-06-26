#ifndef __ACCOUNT_FEE_MANAGER_HPP__
#define __ACCOUNT_FEE_MANAGER_HPP__

class CountedValue {
    private :
        unsigned int to_account;
        unsigned int to_bank;

    public :
        CountedValue(unsigned int countedValue, unsigned int countedFee) {
            this->to_account = countedValue;
            this->to_bank = countedFee;
        }

        unsigned int getValueForAccount();
        unsigned int getValueForBank();
};

class AccountFeeManager {
    private :
        static double BASE_ACCOUNT_FEE_RATE; // 5%
    public :
        CountedValue calcurate(unsigned int value) {
            unsigned int countedFee = static_cast<unsigned int>(value * this->BASE_ACCOUNT_FEE_RATE);
            unsigned int countedValue = value - countedFee;
            return CountedValue(countedValue, countedFee);
        };
};

double AccountFeeManager::BASE_ACCOUNT_FEE_RATE = 0.05;

#endif // __ACCOUNT_FEE_MANAGER_HPP__
