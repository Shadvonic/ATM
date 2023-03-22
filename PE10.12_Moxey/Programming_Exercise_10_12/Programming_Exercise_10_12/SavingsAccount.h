//Marc-Anthony Moxey
//savingAccount.h 
//PE9-20
//DESC this file sets the template for the SavingsAccount.cpp file 

#pragma once
#include <string>
#include <iostream>
#include<iomanip>
#include "DollarAmount.h"
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount
{

public:

	//constructor that sets accountID,accountPIN,accountName,savingsBalance
	SavingsAccount(int, int, std::string, DollarAmount);


	//set functions 
	void setAccountID(int a);
	void setAccountPin(int b);
	void setAccountName(std::string c);


	//function that does calulations 
	void calculateMonthlyInterest();
	void modifyInterestRate(double rate);


	//get functions 
	int getAccountID() const;
	int getAccountPin()  const;
	DollarAmount getSavingsBalance() const;
	std::string getAccountName() const;

	//print functions 
	void h_Output();
	static void printAcct(SavingsAccount* Saver, int arrSize);
	static void printReports(const SavingsAccount* Saver, int arrSize);

	static void checkAcc(SavingsAccount* Saver, int arrSize);



private:
	//data  memebers 
	double annualInterestRate;
	DollarAmount savingsBalance;

	int  accountID;
	int accountPin;
	std::string accountName;


	double withdraw = 0;
	double deposit = 0;

	void setWithdraw(DollarAmount WD);
	void setDeposit(DollarAmount Dep);
	void setSavingsBalance(DollarAmount SB);

	





	//end file 
#endif SAVINGSACCOUNT_H

};

