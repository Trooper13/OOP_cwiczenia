// Author: Mateusz Mitura
// Date: 30.09.2017
// WIT

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

enum Banks { PKO, BGZ, BRE, BPH };

struct Account {
	Banks bank;
	int balance;
};

struct Person {
	char name[20];
	Account account;
};

struct Couple {
	Person he;
	Person she;
};

const Couple *bestClient(const Couple *tablicaPar, int size, Banks bank);

int main()
{
	using std::cout; using std::endl;

	Couple tablicaPar[] = { { { "Johny",{ PKO, 1200 } },{ "Mary",{ BGZ, 1500 } } },
							{ { "Peter",{ BGZ, 1400 } },{ "Suzy",{ BRE, 1500 } } },
							{ { "Kevin",{ PKO, 1600 } },{ "Katy",{ BPH, 1500 } } },
							{ { "Kenny",{ BPH, 1800 } },{ "Lucy",{ BRE, 1500 } } }, 
						  };

	const Couple *p = bestClient(tablicaPar, 4, BGZ);

	cout << p->he.name << " and " << p->she.name
		<< ": " << p->he.account.balance +
		p->she.account.balance << endl;


	return 0;
}

const Couple *bestClient(const Couple *tablicaPar, int size, Banks bank)
{
	int max, sum, idx;
	for (int i = 0; i<size; i++)
		while (tablicaPar[i].he.account.bank == bank || tablicaPar[i].she.account.bank == bank)
		{

		}

}
