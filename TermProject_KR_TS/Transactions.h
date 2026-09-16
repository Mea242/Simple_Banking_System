#ifndef _TRANSACTIONS_
#define _TRANSACTIONS_
#include <iostream>
#include<string>
#include"Customer.h"
#include <fstream>

using namespace std;
class Transactions {
	Customer* customerAcc;
	char transactionType;
	double amount;
	string billName;
	


public:
	void setCustomerAccount(Customer* _customerAcc);
	void setAll(Customer* _customerAcc, string _billName, char _transactionType, double _amount);
	void recordSavingsTransaction(const Transactions& t);
	void recordCheckingTransaction(const Transactions& t);
	void recordAll(const Transactions& t);
	void showCheckingHistory(Customer* _c);
	void showSavingsHistory(Customer* _c);
	void loanList(Customer* _customerAcc);
	
};



#endif