#include <iostream> 
#include <string>;
#include "Savings.h"
using namespace std;

void SavingAccount::setInterestRate(double _interestRate)
{
	if (_interestRate < 0)
	{
		interestRate = 0;
	}
	else
	{
		interestRate = _interestRate;
	}
}
double SavingAccount::getInterestRate() const
{
	return interestRate;
}
SavingAccount::SavingAccount() : Account()
{
	interestRate = 0;
}
SavingAccount::SavingAccount(int _ID, double _balance, Customer* _customer, double _interestRate) :Account(_ID, _balance, _customer)
{
	if (interestRate > 0)
	{
		interestRate = _interestRate;
	}
	else
	{
		interestRate = 0;
	}
}
void SavingAccount::setAll(int _ID, double _balance, Customer* _customer, double _interestRate)
{
	Account::setAll(_ID, _balance, _customer);
	setInterestRate(_interestRate);
}
void SavingAccount::payInterest()
{
	double interest;
	interest = interestRate * balance;
	balance = balance + interest;
}
void SavingAccount::transfer(double amount, SavingAccount& destinationAccount)
{
	if (balance > amount)
	{
		balance = balance - amount;
		destinationAccount.balance = destinationAccount.balance + amount;
	}
	else
	{
		cout << "Not enough money to transfer" << endl;
	}
}

