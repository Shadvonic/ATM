//Marc-Anthony Moxey 
//savingAccount.cpp
//PE9-20

#include "SavingsAccount.h"
#include <iostream>
#include <string>


SavingsAccount::SavingsAccount(int ID, int PIN, std::string NAME, DollarAmount BAL)
	:accountID{ ID },
	accountPin{ PIN },
	accountName{ NAME }

{
	
	annualInterestRate = .03;
	(BAL);

}


// Sets the value for the int accountID of the SavingsAccount object
void SavingsAccount::setAccountID(int acctID) {
	accountID = acctID;
}


// Sets the value for the int accountPIN of the SavingsAccount object
void SavingsAccount::setAccountPin(int acctPin) {
	accountPin = acctPin;
}


// Sets the value for the string accountName of the SavingsAccount object
void SavingsAccount::setAccountName(std::string acctName) {
	accountName = acctName;
}


// Returns the int accountId of the SavingsAccount object
int SavingsAccount::getAccountID() const {
	return accountID;
}


// Returns the int accountPin of the SavingsAccount object
int SavingsAccount::getAccountPin() const {
	return accountPin;
}


// Returns the string accountName of the SavingsAccount object
std::string SavingsAccount::getAccountName() const {
	return accountName;
}

// member function  calculates the monthly interest by multiplying the savingsBalance by annualInterestRate divided by 12
void SavingsAccount::calculateMonthlyInterest() {
	savingsBalance.addInterest((annualInterestRate / 12));
}

//a static member function that sets the static annualInterestRate to a new value

void SavingsAccount::modifyInterestRate(double rate) {
	if (rate <= 0) {
		rate = .03;
	}
	annualInterestRate = rate;
}

//a  member function that sets the savingsBalance to a new value of user deposit ++
void SavingsAccount::setDeposit(DollarAmount Dep) {
	if (Dep.getAmount() < 0) {
		Dep.setAmount(0);
	}
	
	savingsBalance = savingsBalance +  Dep;
}

//a  member function that sets the savingsBalance to a new value of user withdraw --
void SavingsAccount::setWithdraw(DollarAmount WD) {

	if (WD.getAmount() < 0 || WD.getAmount() > savingsBalance.getAmount()) {

		WD.setAmount(0);
	}
	savingsBalance = savingsBalance - WD;
}

void SavingsAccount::setSavingsBalance(DollarAmount SB) {
	if (SB.getAmount() < 0) {
		SB.setAmount(0);
	}
	savingsBalance = SB;
}
//Returns the double  of the SavingsAccount object
DollarAmount SavingsAccount::getSavingsBalance() const {
	return savingsBalance; 
}


void SavingsAccount::h_Output() {
	std::cout << "\n";
	std::cout << std::setw(20) << "SAVING Account Reports" << std::endl << "\n";
	std::cout << std::left << std::setw(9) << "USER"
		<< std::setw(10) << "ID" << std::setw(7)
		<< "Pin" << std::setw(10) << "Name"
		<< std::setw(10) << "Balance"
		<< std::endl << std::endl;
	std::cout << "\n\n" << std::endl;
}

void SavingsAccount::printReports(const SavingsAccount* Saver, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{

		// outputs the accountID,accountPIN,accountName,savingsBalance;
		std::cout << "Saver " << i + 1 << "  ";
		std::cout << std::left << std::setw(10) << Saver[i].getAccountID()
			<< std::setw(10) << Saver[i].getAccountPin()
			<< std::setw(10) << Saver[i].getAccountName()
			<< Saver[i].getSavingsBalance().toString() << std::endl;
	}
}

//check accPin and accID matches object in array
//if accId and accPin match allow user to make a trans
void SavingsAccount::checkAcc(SavingsAccount Saver[], int arrSize) {
	DollarAmount amount{ 0 };

	int testID;
	int testPin;
	std::cout << "Enter account ID: "; 
	std::cin >> testID;
	std::cout << "Enter account PIN: ";
	std::cin >> testPin;

	for (int i = 0; i < arrSize; i++) {
		if (testID == Saver[i].getAccountID() && testPin == Saver[i].getAccountPin()) {

			int userDeposit, userWithdraw, dollar, cents;
			char selections;
			bool checkPassed = true; 

			while (checkPassed) {
			
				std::cout << "Enter 1 to depost " << "\nEnter 2 to withdraw " << std::endl;
				std::cin >> selections; 
			

				switch (selections) {

					case '1':
						
						std::cout << "How much would like to deposit? Please enter dollar first then cents" << std::endl;
						std::cin >> dollar; 
						std::cout << "Please enter cents: ";
						std::cin >> cents; 
						std::cout << "\n\n ";
						userDeposit = (dollar * 100) + cents;
						amount.setAmount(dollar, cents);
						Saver[i].setDeposit(amount); 
						std::cout << "\n\n";
						std::cout <<"Balance: " << Saver[i].getSavingsBalance().toString() << std::endl;
						std::cout << "\n\n";
						break;

					case '2': 

						std::cout << "How much would like to withdraw? Please enter dollar first then cents" << std::endl;
						std::cin >> dollar;
						std::cout << "Please enter cents: ";
						std::cin >> cents;
						std::cout << "\n\n ";
						userWithdraw = (dollar * 100) + cents;
						amount.setAmount(dollar, cents);
						Saver[i].setWithdraw(amount);
						std::cout << "\n\n ";
						std::cout <<"Balance: " << Saver[i].getSavingsBalance().toString() << std::endl;
						std::cout << "\n\n ";
						break;

				} 
				

					
			}
		} 
	}
	std::cout << "There was a problem with account ID or account Pin " << std::endl;

	
}

/*int main()
{
	int cent;
	int dol;
	cout << "enter doll";
	cin >> dol;

	cout << "enter sent";
	cin >> cent;

	int total = (dol * 100) + cent;

	cout << total;
	return 0;
} */ 

