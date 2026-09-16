#pragma once
#ifndef _CUSTOMER_
#define _CUSTOMER_

#include<iostream>
#include<string>
using namespace std;

class Customer {
	string fname, lname, address, email;
	long long phone;

public:
	Customer();
	Customer(string _fname, string _lname, string _address, string _email, long long _phone);
	void setFname(string _fname);
	void setLname(string _lname);
	void setAddress(string _address);
	void setEmail(string _email);
	void setPhone(long long _phone);
	void setAll(string _fname, string _lname, string _address, string _email, long long _phone);
	string getFname()const;
	string getLname()const;
	string getAddress()const;
	string getEmail()const;
	long long getPhone()const;
	void printInfo();
	
};


#endif //!_CUSTOMER_
