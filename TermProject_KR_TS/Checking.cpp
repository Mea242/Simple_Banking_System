#include "Checking.h"



Checking::Checking() :Account()
{
	overDraftLimit = 0;
	overdraftCurrent = 0;
}
Checking::Checking(int _ID, int _balance, Customer* _customer, double _limit) :Account(_ID, _balance, _customer)
{
	setOverDraftLimit(_limit);
	overdraftCurrent = 0;
}
void Checking::setOverDraftLimit(double _limit)
{
	if (_limit > 0)
		overDraftLimit = _limit;
	else
		overDraftLimit = 0;
}
double Checking::getOverDraftLimit()const
{
	return overDraftLimit;
}
void Checking::setAll(int _ID, int _balance, Customer* _customer, double _limit)
{
	Account::setAll(_ID, _balance, _customer);
	setOverDraftLimit(_limit);
}
void Checking::withdrawMoney(double _amount)
{
	if (_amount > 0)
	{
		if (balance - _amount > 0)
		{
			balance = balance - _amount;
			withdrawalCounter++;
			cout << "Current Balance: " << balance << endl;
		}
		else if (overdraftCurrent + 20 + _amount >= overDraftLimit)
		{
			balance = balance - _amount - 20;
			overdraftCurrent = _amount + 20;
			withdrawalCounter++;
			cout << "Current Balance: " << balance << " Current Overdraft: " << overdraftCurrent << endl;
		}
		else
		{
			cout << "OverDraft limit reached. Transaction Denied." << endl;
		}

	}

}
void Checking:: payBill(double _amount)
{
	if (_amount > 0)
	{
		if (balance - _amount > 0)
		{
			balance = balance - _amount;
			withdrawalCounter++;
			cout << "Bill payed. Balance: " << balance << endl;
		}
		else if (overdraftCurrent + 20 + _amount >= overDraftLimit)
		{
			balance = balance - _amount - 20;
			overdraftCurrent = _amount + 20;
			withdrawalCounter++;
			cout << "Bill payed. Balance: " << balance << " Current Overdraft: " << overdraftCurrent << endl;
		}
		else
		{
			cout << "OverDraft limit reached. Transaction Denied. Bill not payed." << endl;
		}

	}
}



