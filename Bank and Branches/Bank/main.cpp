#include <iostream>
#include "Branch.h"
#include "Bank.h"

using namespace std;
int main()
{
	Branch b;
	Branch a[10];
	a[0] = Branch("Sofia", 5, 11);
	a[1] = Branch("Vladaya", 6, 12);
	a[2] = Branch("Cherniche", 7, -14);
	a[3] = Branch("Montana", 8, -11);
	a[4] = Branch("Pernik", 9, 13);
	a[5] = Branch("Stara Zagora", 10, 15);
	a[6] = Branch("Sofia - 2", 1, 10);
	Bank bank1(a);
	Bank bank2; /// default bank - no work coeff in branches
	Bank bank3 = bank1;

	race(bank1, bank2);

	return 0;
}
