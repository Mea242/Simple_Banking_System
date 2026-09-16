#include "Transactions.h"
#include <string>
#include <iostream>

void Transactions::setCustomerAccount(Customer* _customerAcc)
{
	customerAcc = _customerAcc;
}
void Transactions::setAll(Customer* _customerAcc, string _billName, char _transactionType, double _amount)
{
	customerAcc = _customerAcc;
	billName = _billName;
	transactionType = _transactionType;
	if (_amount < 0)
		amount = 0;
	else
		amount = _amount;
}
void Transactions::recordSavingsTransaction(const Transactions& t)
{
	fstream file("c:\\temp\\SavingTransactionHistory.txt", ios::out | ios::app);
	file <<t.customerAcc->getLname() << "\t" << t.billName << "\t" << t.amount << "\t" << t.transactionType << endl;
	file.close();
}
void Transactions::recordCheckingTransaction(const Transactions& t)
{
	fstream file("c:\\temp\\CheckingTransactionHistory.txt", ios::out | ios::app);
	file <<t.customerAcc->getLname() << "\t" << t.billName << "\t" << t.amount << "\t" << t.transactionType << endl;
	file.close();
}
void Transactions::recordAll(const Transactions& t)
{
	fstream file("c:\\temp\\TransactionHistory.txt", ios::out | ios::app);
	file << t.customerAcc->getEmail() << "\t" << t.customerAcc->getLname() << "\t" << t.billName << "\t" << t.amount << "\t" << t.transactionType << endl;
	file.close();
}
void Transactions::showCheckingHistory(Customer* _c)
{
	fstream file("c:\\temp\\CheckingTransactionHistory.txt", ios::in);
	if (!file)
		cout << "Error, could not open file" << endl;
	else
	{
		char _type;
		double _amount;
		string lname, _billName;
		
		
		cout << "Customer\t" << "Transaction Name" << " " << "Amount   " << "Transaction Code" << endl;
		while (file >> lname)
		{
			if (lname == _c->getLname())
			{
				
				cout << lname << "\t";
				file >> _billName;
				cout << _billName << "\t";
				file >> _amount;
				cout << _amount << "\t";
				file >> _type;
				cout << _type << endl;
			}

		}

	}
	file.close();
}
void Transactions::showSavingsHistory(Customer* _c)
{
	fstream file("c:\\temp\\SavingTransactionHistory.txt", ios::in);
	if (!file)
		cout << "Error, could not open file" << endl;
	else
	{
		char _type;
		double _amount;
		string lname, _billName;

		cout << "Customer\t" << "Transaction Name" << "   " << "Amount   " << "Transaction Code" << endl;
		while (file >> lname)
		{
			if (lname == _c->getLname())
			{
				cout << lname << "\t";
				file >> _billName;
				cout << _billName << "\t";
				file >> _amount;
				cout << _amount << "\t";
				file >> _type;
				cout << _type << endl;
			}

		}

	}
	file.close();
}
void Transactions::loanList(Customer* _customerAcc)
{
	fstream file("c:\\temp\\ApprovedLoanList.txt", ios::out | ios::app);
	file << _customerAcc->getFname() << " " << _customerAcc->getLname() << " \t"<< _customerAcc->getPhone() << " \t" << _customerAcc->getEmail() << endl;
	file.close();
}