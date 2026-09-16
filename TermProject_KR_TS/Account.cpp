#include <iostream>
#include <iomanip>

#include "Customer.h"
#include "Account.h"
using namespace std;

void Account::setID(int _ID)

{

	if (_ID < 0)

	{

		ID = 0;

	}

	else

	{

		ID = _ID;

	}

}

void Account::setBalance(double _balance)

{

	if (_balance < 0)

	{

		balance = 0;

	}

	else

	{

		balance = _balance;

	}

}

void Account::setAccountCustomer(Customer* _accountCustomer)
{
	accountCustomer = _accountCustomer;
}

Customer* Account::getAccountCustomer() const
{
	return accountCustomer;
}

int Account::getID() const

{

	return ID;

}

double Account::getBalance() const

{

	return balance;

}

void Account::setAll(int _ID, double _balance, Customer* _accountCustomer)

{

	setID(_ID);

	setBalance(_balance);

	setAccountCustomer(_accountCustomer);

}

Account::Account()

{
	ID = 0;
	balance = 0;
	accountCustomer = nullptr;

}
Account::Account(int _ID, double _balance, Customer* _customer)
{
	setID(_ID);
	setBalance(_balance);
	setAccountCustomer(_customer);

}
void Account::depositMoney(double amount)
{
	if (amount > 0)
	{
		balance = balance + amount;
		depositsCounter++;
	}
	else
	{
		cout << "Must be a positive amount!" << endl;
	}


}
void Account::withdrawMoney(double amount)
{
	if (amount <= 0)
	{
		cout << "Must be a positive number" << endl;
		return;
	}

	if (amount <= balance)
	{
		balance = balance - amount;
		withdrawalCounter++;
	}
	else
	{
		cout << "Insufficient funds!" << endl;
	}
}
void Account::printInfo()
{
	if (accountCustomer != nullptr)
	{
		cout << accountCustomer->getFname();
		cout << " ";
		cout << accountCustomer->getLname();
		cout << setw(15);
	}
	else
	{
		cout << "No customer assigned to account" << endl;
	}

	cout << ID << setw(15) << balance << setw(15) << withdrawalCounter << setw(20) << depositsCounter << endl;

}
void Account::printHeader()
{
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	cout << "Name" << setw(20) << "ID" << setw(20) << "Balance" << setw(20) << "Withdrawals" << setw(20) << "Deposits" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;

}
void Account::payBill(double amount)
{
	if (balance - amount > 0)
	{
		balance = balance - amount;
		cout << "Bill payed. Balance: " << balance << endl;
	}
	else
		cout << "Insufficient Funds." << endl;
}
