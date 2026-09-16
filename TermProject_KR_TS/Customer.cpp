#include "Customer.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Customer::Customer()
{
	fname = "";
	lname = "";
	address = "";
	email = "";
	phone = 0LL;
}
Customer::Customer(string _fname, string _lname, string _address, string _email, long long _phone)
{
	setAll(_fname, _lname, _address, _email, _phone);
}
void Customer::setFname(string _fname)
{
	fname = _fname;
}
void Customer::setLname(string _lname)
{
	lname = _lname;
}
void Customer::setAddress(string _address)
{
	address = _address;
}
void Customer::setEmail(string _email)
{
	email = _email;
}
void Customer::setPhone(long long _phone)
{
	if (_phone >= 1000000000LL &&_phone <= 9999999999LL)  //(_phone.length() == 10)
	{
		phone = _phone;
	}


}
void Customer::setAll(string _fname, string _lname, string _address, string _email, long long _phone)
{
	fname = _fname;
	lname = _lname;
	address = _address;
	email = _email;
	setPhone(_phone);
}
string Customer::getFname()const
{
	return fname;
}
string Customer::getLname()const
{
	return lname;
}
string Customer::getAddress()const
{
	return address;
}
string Customer::getEmail()const
{
	return email;
}
long long int Customer::getPhone()const
{
	return phone;
}
void Customer::printInfo()
{
	cout << fname << " " << lname <<" ||" << setw(10) << right << email << setw(8) << right << "||" << phone;
	
}




