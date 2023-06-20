#include <iostream>
#include <vector>

#include "Account.hpp"

// struct Bank {
//   int liquidity;
//   std::vector<Account *> clientAccounts;

//   Bank() : liquidity(0) {}

//   friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank) {
//     p_os << "Bank informations : " << std::endl;
//     p_os << "Liquidity : " << p_bank.liquidity << std::endl;
//     // for (auto &clientAccount : p_bank.clientAccounts)
//     //   p_os << *clientAccount << std::endl;
//     return (p_os);
//   }
// };

// int main() {
//   Account accountA = Account();
//   accountA.id = 0;
//   accountA.value = 100;

//   Account accountB = Account();
//   accountB.id = 1;
//   accountB.value = 100;

//   Bank bank = Bank();
//   bank.liquidity = 999;
//   bank.clientAccounts.push_back(&accountA);
//   bank.clientAccounts.push_back(&accountB);

//   bank.liquidity -= 200;
//   accountA.value += 400;

//   std::cout << "Account : " << std::endl;
//   std::cout << accountA << std::endl;
//   std::cout << accountB << std::endl;

//   std::cout << " ----- " << std::endl;

//   std::cout << "Bank : " << std::endl;
//   std::cout << bank << std::endl;

//   return (0);
// }

int main() {
	Account acc1 = Account(100);
	Account acc2 = Account(200);
	
	std::cout << acc1 << std::endl;
	std::cout << acc2 << std::endl;
	return 0;
}