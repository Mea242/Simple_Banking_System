#pragma once
#ifndef _CHECKING_
#define _CHECKING_
#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

class Checking :public Account {
	double overDraftLimit, overdraftCurrent;

public:
	Checking();
	Checking(int _ID, int _balance, Customer* _customer, double _limit);
	void setOverDraftLimit(double _limit);
	double getOverDraftLimit()const;
	void setAll(int _ID, int _balance, Customer* _customer, double _limit);
	void withdrawMoney(double _amount);
	void payBill(double amount);
	
};

#endif //!_CHECKING_