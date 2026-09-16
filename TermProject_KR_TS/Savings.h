#pragma once
#ifndef _SAVINGACCOUNT_
#define _SAVINGACCOUNT_
#include<iostream>
#include<string>
using namespace std;
#include"Account.h"

class SavingAccount : public Account {
	double interestRate;
public:
	SavingAccount();
	SavingAccount(int _ID, double _balance, Customer* _customer, double _interestRate);
	void setInterestRate(double _interestRate);
	double getInterestRate() const;
	void setAll(int _ID, double _balance, Customer* _customer, double _interestRate);
	void payInterest();
	void transfer(double amount, SavingAccount& destinationAccount);
};

#endif
