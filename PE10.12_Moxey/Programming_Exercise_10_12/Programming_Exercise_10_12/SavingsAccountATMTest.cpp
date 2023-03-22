//Marc-Anthony Moxey
//SavingsAccountTest.cpp
// PE 9-20
// SavingsAccountTest is a tester program for the SavingsAccountTest class
//stores data into the 3  saver information in an array of objectts
//uses print functions to  output savings account report 

#include "SavingsAccount.h"
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	unsigned const int numSavers = 3;

	SavingsAccount* Saver = new SavingsAccount[numSavers]
	{
		{75813592, 4532, "Bob", DollarAmount{2000,0}},
		{71164357, 3049, "Will", DollarAmount{3000,0}},
		{81437114, 5673, "Bill", DollarAmount{1600,0}}
	};


	//Saver[0].h_Output();
	//SavingsAccount::printReports(Saver, numSavers);

	SavingsAccount::checkAcc(Saver, numSavers); 

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
