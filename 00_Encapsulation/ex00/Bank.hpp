#ifndef BANK_HPP
# define BANK_HPP

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>

#define ERRMSG(x) std::string("Error: ") + std::string(x)
#define NOTIMSG(x) std::string("Notice : ") + std::string(x)

class Bank {
    private:
        static int _AccountIDCounts;
        static float _interestRate;
        int _liquidity;
        class Account {
            private:
                int _id;
                int _value;

            protected:
                friend class Bank;

            public:
                int getId() const;
                int getValue() const;
        };
        class LoanRecord {
            private:
                int _id;
                int _value;
                int _interest;
                int _duration_months;
                time_t _time;

            protected:
                friend class Bank;

            public:
                int getId() const;
                int getValue() const;
                int getInterest() const;
                int getDurationMonths() const;
                time_t getTime() const;
        };
        
        std::map<int, Account> _clientAccounts;
        std::map<int, std::vector<LoanRecord> > _loanRecords;
        void setLiquidity(int liquidity);
        void addLoanRecordHistory(LoanRecord &loanRecord);
        LoanRecord createNewLoanRecord(int accountId, int value, int duration);
        Account createNewAccount(void);

    public:
        Bank();
        Bank(int liquidity);
        ~Bank();
        int getLiquidity() const;
        void addLiquidity(int liquidity) throw(std::exception);

        int makeAccount() throw(std::exception);
        int closeAccount(int id) throw(std::exception);
        void deposit(int id, int value) throw(std::exception);
        void withdraw(int id, int value) throw(std::exception);

        void showLoanRecords(int id) throw(std::exception);
        void takeLoan(int id, int value, int duration) throw(std::exception);
        void repayLoan(int id, int value) throw(std::exception);

        Account& operator[](int id) throw(std::exception);
        friend std::ostream &operator<<(std::ostream &p_os, const Bank::LoanRecord &p_loanRecord);
        friend std::ostream &operator<<(std::ostream &p_os, const Bank::Account &p_account);
        friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
};






#endif // BANK_HPP