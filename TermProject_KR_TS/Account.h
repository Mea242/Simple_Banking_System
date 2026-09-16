#ifndef _ACCOUNT_
#define _ACCOUNT_
#include <iostream> 
#include <iomanip>
#include "Customer.h"
using namespace std;

class Account {
	Customer* accountCustomer;
protected:
	int ID, withdrawalCounter = 0, depositsCounter = 0;
	double balance;
public:
	Account();
	Account(int _ID, double _balance, Customer* _customer);
	void setID(int _ID);
	void setBalance(double _balance);
	void setAccountCustomer(Customer* _accountCustomer);
	Customer* getAccountCustomer() const;
	int getID() const;
	double getBalance() const;
	void setAll(int _ID, double _balance, Customer* _accountCustomer);
	void depositMoney(double amount);
	void withdrawMoney(double amount);
	void printInfo();
	void printHeader();
	void payBill(double amount);


};

#endif //!_ACCOUNT_


