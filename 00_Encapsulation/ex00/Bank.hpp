#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <vector>
#include "Account.hpp"

class Bank {
	private :
		std::vector<Account *> clientAccounts;
		int liquidity;

	public :
		Bank();
		~Bank();

		void addAccount(Account *account);
		void removeAccount(Account *account);
		
		void setLiquidity(int liquidity);
		int getLiquidity(void) const;
}

std::ostream &operator<<(std::ostream &os, const Bank &ref);

#endif