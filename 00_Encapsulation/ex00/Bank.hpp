#ifndef __BANK_HPP__
#define __BANK_HPP__

#include "Account.hpp"
#include "AccountManager.hpp"
#include "AccountFeeManager.hpp"

class Bank {
	private :
		AccountManager accountManager;
		AccountFeeManager accountFeeManager;
		int liquidity;

	public :
		Bank();
		Bank(int liquidity);
		~Bank();

		int getLiquidity(void) const;
		AccountManager &getAccountManager(void) const;

		bool addAccount(Account *account);
		bool removeAccount(Account *account);
		Account *findAccountById(unsigned int id);
};

std::ostream &operator<<(std::ostream &os, const Bank &ref);

#endif