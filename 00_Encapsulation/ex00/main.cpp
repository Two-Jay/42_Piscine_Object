#include "Bank.hpp"
#include <iostream>

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    try {
        Bank bank = Bank();

        bank.addLiquidity(999);

        std::cout << bank;

        int accountA = bank.makeAccount();
        int accountB = bank.makeAccount();
        int accountC = bank.makeAccount();

        bank.deposit(accountA, 100);
        bank.deposit(accountB, 200);
        bank.deposit(accountC, 300);

        bank.withdraw(accountA, 50);
        std::cout << bank;

        bank.closeAccount(accountB);
        std::cout << bank;

        bank.takeLoan(accountC, 100, 12);
        bank.showLoanRecords(accountC);

        bank.repayLoan(accountC, 50);
        bank.showLoanRecords(accountC);

        bank.repayLoan(accountC, 50);

        std::cout << bank;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}