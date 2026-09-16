#include <iostream>
#include <string>
#include "Customer.h"
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transactions.h"
#include <fstream>

using namespace std;


int main()
{
	//Variable Declaration
	int ans, customerCount = 0, checkingCount = 0, savingsCount = 0, ID, index;
	double overdraft, interest, checkingBalance, amount, balance;
	bool customerFound = false, customerFound2;
	long long phone;
	Transactions t, temp;
	string fname, lname, email, address, billName;
	Customer* tempCustomer;
	Customer customerList[20];
	Checking checkingAccount[20];
	SavingAccount savingAccount[20];
	char opt;


	cout << "Please Choose from the list of options below: " << endl << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "1- Create Checking Account" << endl;
	cout << "2- Create Savings Account" << endl;
	cout << "3- View Account Information" << endl;
	cout << "4- Modify Account" << endl;
	cout << "5- Delete Account" << endl;
	cout << "6- Transfer Between Accounts" << endl;
	cout << "7- Deposit Money" << endl;
	cout << "8- Withdraw Money" << endl;
	cout << "9- Pay Bill" << endl;
	cout << "10- Add Customer to approved loan list" << endl;
	cout << "11- Print All Account Info" << endl;
	cout << "12- Show Transaction History" << endl;
	cout << "13- Exit Program" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Enter option: ";
	cin >> ans;


	while (ans != 13)
	{

		switch (ans)
		{
		case 1: //create checking Account
			cout << "Is this an existing Customer(y or n): ";
			cin >> opt;
			if (opt == 'y' || opt == 'Y')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email address: ";
				cin >> email;
				cout << "ID: ";
				cin >> ID;
				for (int i = 0; i < customerCount; i++) // checks for existing Customer
				{
					while (checkingAccount[i].getID() == ID)
					{
						cout << "Duplicate ID number, Enter new ID: " << endl;
						cin >> ID;
					}
					if (customerList[i].getEmail() == email && customerList[i].getLname() == lname)
					{
						customerFound = true;
						cout << "This is an existing customer" << endl;
						tempCustomer = &customerList[i];

						cout << "Checking Account Balance: " << endl;
						cin >> checkingBalance;
						while (checkingBalance < 0)
						{
							cout << "Invalid. Enter Positive Numbers: " << endl;
							cin >> checkingBalance;
						}
						cout << "Overdraft Limit: " << endl;
						cin >> overdraft;
						while (overdraft < 0)
						{
							cout << "Invalid. Enter Positive Numbers: " << endl;
							cin >> overdraft;
						}
						checkingAccount[checkingCount].setAll(ID, checkingBalance, tempCustomer, overdraft);
						checkingCount++;
						cout << "New Checking Account Added." << endl;

						break;
					}
					else
					{
						customerFound = false;
					}

				}
				if (!customerFound)
					cout << "Account not found!" << endl;

			}
			else if (opt == 'n' || opt == 'N') // new customer
			{
				cout << "First Name: ";
				cin >> fname;
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				cout << "ID: ";
				cin >> ID;
				for (int i = 0; i < customerCount; i++)
				{
					while (checkingAccount[i].getID() == ID)
					{
						cout << "Duplicate ID number, Enter new ID: " << endl;
						cin >> ID;
					}
					
					while (customerList[i].getEmail() == email)
					{
						cout << "This is a duplicate email" << endl;
						cout << "Enter Email: ";
						cin >> email;							
					}
						
					
				}
				
				cout << "Phone Number: ";
				cin >> phone;
				while (!(phone >= 1000000000LL && phone <= 9999999999LL))
				{
					cout << "Invalid phone number. Enter a 10 digit phone number: " << endl;
					cin >> phone;
				}

				cin.ignore();
				cout << "Address: ";
				getline(cin, address);

				for (int i = 0; i < customerCount; i++) // checks for existing Customer
				{
					customerFound = false;
					if (customerList[i].getEmail() == email && customerList[i].getLname() == lname)
					{
						cout << "This is an existing Customer" << endl;
						customerFound = true;
						index = i;
						break;
					}


				}
				if (customerFound == true)
				{
					cout << "Continue adding checking account under existing customer(y or n): ";
					cin >> opt;
					if (opt == 'Y' || opt == 'y')
					{
						cout << "This is an existing customer" << endl;
						tempCustomer = &customerList[index];

						cout << "Checking Account Balance: " << endl;
						cin >> checkingBalance;
						while (checkingBalance < 0)
						{
							cout << "Invalid. Enter Positive Numbers: " << endl;
							cin >> checkingBalance;
						}
						cout << "Overdraft Limit: " << endl;
						cin >> overdraft;
						while (overdraft < 0)
						{
							cout << "Invalid. Enter Positive Numbers: " << endl;
							cin >> overdraft;
						}
						checkingAccount[checkingCount].setAll(ID, checkingBalance, tempCustomer, overdraft);
						checkingCount++;
						cout << "New Checking Account Added." << endl;
					}
					else if (opt == 'n' || opt == 'N')
					{
						break;
					}
				}
				else if (customerFound == false)
				{
					customerList[customerCount].setAll(fname, lname, address, email, phone);
					tempCustomer = &customerList[customerCount];
					customerCount++;
					cout << "New Customer Added" << endl << endl;

					cout << "Checking Account Balance: " << endl;
					cin >> checkingBalance;
					while (checkingBalance < 0)
					{
						cout << "Invalid. Enter Positive Numbers: " << endl;
						cin >> checkingBalance;
					}
					cout << "Overdraft Limit: " << endl;
					cin >> overdraft;
					while (overdraft < 0)
					{
						cout << "Invalid. Enter Positive Numbers: " << endl;
						cin >> overdraft;
					}
					checkingAccount[checkingCount].setAll(ID, checkingBalance, tempCustomer, overdraft);
					checkingCount++;
					cout << "New Checking Account Added." << endl;
				}


			}
			else
				cout << "Invalid option." << endl;
			break;

		case 2: //Create a savings account
		{
			//variables for 
			int savingsID;
			double savingsBalance, savingsInterestRate;
			char savingsAnswer;
			string savingsFname, savingsLname, savingsAddress, savingsEmail;
			long long savingsPhone;
			Customer* selectedCustomer = nullptr;

			cout << "Are you an existing customer?(Y or N): ";
			cin >> savingsAnswer;

			if (savingsAnswer == 'Y' || savingsAnswer == 'y')
			{
				string searchFname, searchLname;
				cout << "First Name: ";
				cin >> searchFname;
				cout << "Last Name: ";
				cin >> searchLname;

				for (int i = 0; i < customerCount; i++) //Searches for first and last name in records
				{
					if (customerList[i].getFname() == searchFname && customerList[i].getLname() == searchLname)
					{
						selectedCustomer = &customerList[i];
						break;
					}

				}

			}
			else if (savingsAnswer == 'N' || savingsAnswer == 'n') //Creates new customer
			{
				cout << "Creating Customer..." << endl;

				cout << "Enter a first name: ";
				cin >> savingsFname;
				cout << "Enter a last name: ";
				cin >> savingsLname;
				cin.ignore();
				cout << "Enter an address: ";
				getline(cin, savingsAddress);
				cout << "Enter an email: ";
				cin >> savingsEmail;
				cout << "Enter a phone number: ";
				cin >> savingsPhone;

				customerList[customerCount].setAll(savingsFname, savingsLname, savingsAddress, savingsEmail, savingsPhone);
				selectedCustomer = &customerList[customerCount];
				customerCount++;

				cout << "Customer created!" << endl;
			}
			else
			{
				cout << "Invalid choice" << endl;
				break;
			}

			if (selectedCustomer == nullptr)
			{
				cout << "Customer not found" << endl;
				break;
			}
			else
			{
				cout << "Enter ID: ";
				cin >> savingsID;
				cout << "Enter a balance: ";
				cin >> savingsBalance;
				if (savingsBalance < 0)
				{
					cout << "Balance must be a positive amount" << endl;
					break;
				}
				cout << "Enter an interest rate: ";
				cin >> savingsInterestRate;
				if (savingsInterestRate < 0)
				{
					cout << "Interest rate must be a positive number" << endl;
				}
				if (selectedCustomer == nullptr)
				{
					cout << "Account cannot be created without valid customer identification" << endl;
					break;
				}

				savingAccount[savingsCount] = SavingAccount(savingsID, savingsBalance, selectedCustomer, savingsInterestRate);
				savingsCount++;

				cout << "Savings Account created!" << endl;
			}

		}
		break;

		case 3: //View Account information(fix print functions)
			cout << "Checking or Savings Account(C or S): ";
			cin >> opt;
			if (opt == 'C' || opt == 'c')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email Address: ";
				cin >> email;
				for (int i = 0; i < customerCount; i++) // checks for existing Customer
				{
					customerFound = false;
					if (checkingAccount[i].getAccountCustomer()->getLname() == lname && checkingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						checkingAccount[i].printHeader();
						checkingAccount[i].printInfo();
						break;
					}
				}
				if (customerFound = false)
					cout << "Account not found." << endl;
			}
			else if (opt == 'S' || opt == 's')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email address: ";
				cin >> email;
				for (int i = 0; i < customerCount; i++) // checks for existing Customer
				{
					customerFound = false;
					if (savingAccount[i].getAccountCustomer()->getLname() == lname && savingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						savingAccount[i].printHeader();
						savingAccount[i].printInfo();
						break;
					}
				}
				if (customerFound == false)
					cout << "Account not found." << endl;
			}
			else
				cout << "Invalid option." << endl;
			break;

		case 4://modify account
		{
			char checkOrSave;
			bool modifyFound = false;
			int modifyID, modifyIndex = -1;
			cout << "Would you like to modify a checking account or savings account(C or S): ";
			cin >> checkOrSave;
			cout << "Enter the ID of the account you would like to edit: ";
			cin >> modifyID;
			if (checkOrSave == 'C' || checkOrSave == 'c')
			{
				for (int i = 0; i < checkingCount; i++)//searching checking accounts
				{
					if (checkingAccount[i].getID() == modifyID)
					{
						modifyFound = true;
						modifyIndex = i;
						break;
					}
				}

				if (modifyFound)
				{
					int checkingChoice;
					int checkingsIDMod;
					double checkingsBalanceMod, checkingsInterestRateMod;
					string checkingsFnameMod, checkingsLnameMod, checkingsAddressMod, checkingsEmailMod;
					long long checkingsPhoneMod;
					Customer* CustomerModify = checkingAccount[modifyIndex].getAccountCustomer();
					cout << "Pick what you would like to modify: " << endl;
					cout << "1 - Customer Info" << endl;
					cout << "2 - ID" << endl;
					cout << "3 - Balance" << endl;
					cout << "4 - Overdraft Limit" << endl;
					cin >> checkingChoice;

					if (checkingChoice == 1) //updating customer information
					{
						cout << "Update information in the following: ";

						cout << "Enter a first name: ";
						cin >> checkingsFnameMod;
						cout << "Enter a last name: ";
						cin >> checkingsLnameMod;
						cin.ignore();
						cout << "Enter an address: ";
						getline(cin, checkingsAddressMod);
						cout << "Enter an email: ";
						cin >> checkingsEmailMod;
						cout << "Enter a phone number: ";
						cin >> checkingsPhoneMod;

						CustomerModify->setAll(checkingsFnameMod, checkingsLnameMod, checkingsAddressMod, checkingsEmailMod, checkingsPhoneMod);

						cout << "Customer's information has been updated!" << endl;
					}
					else if (checkingChoice == 2) //updating ID
					{
						int NewID;
						cout << "What would you like your new ID to be: ";
						cin >> NewID;

						if (NewID >= 0)
						{
							checkingAccount[modifyIndex].setID(NewID);
							cout << "ID has been updated!" << endl;
						}
						else
						{
							cout << "Invalid ID" << endl;
						}
					}
					else if (checkingChoice == 3) //updating balance
					{
						double NewBalance;
						cout << "What would you like your new balance to be: ";
						cin >> NewBalance;

						if (NewBalance >= 0)
						{
							checkingAccount[modifyIndex].setBalance(NewBalance);
							cout << "Balance has been updated!" << endl;
						}

					}
					else if (checkingChoice == 4) //updating overdraft limit
					{
						double NewOverdraftLimit;
						cout << "What would you like your new overdraft limit to be: ";
						cin >> NewOverdraftLimit;

						if (NewOverdraftLimit >= 0)
						{
							checkingAccount[modifyIndex].setOverDraftLimit(NewOverdraftLimit);
							cout << "Overdraft limit has been updated" << endl;
						}
						else
						{
							cout << "Invalid overdraft limit" << endl;
						}
					}
				}
			}
			else if (checkOrSave == 'S' || checkOrSave == 's')
			{
				for (int i = 0; i < savingsCount; i++)
				{
					if (savingAccount[i].getID() == modifyID)
					{
						modifyFound = true;
						modifyIndex = i;
						break;
					}
				}

				if (modifyFound)
				{
					int savingChoice;
					int savingsIDMod;
					double savingsBalanceMod, savingsInterestRateMod;
					string savingsFnameMod, savingsLnameMod, savingsAddressMod, savingsEmailMod;
					long long savingsPhoneMod;
					Customer* CustomerMod = savingAccount[modifyIndex].getAccountCustomer();

					cout << "Pick what you would like to modify: " << endl;
					cout << "1 - Customer Info" << endl;
					cout << "2 - ID" << endl;
					cout << "3 - Balance" << endl;
					cout << "4 - Interest Rate" << endl;
					cin >> savingChoice;

					if (savingChoice == 1) //updating customer info
					{
						cout << "Update information in the following: ";

						cout << "Enter a first name: ";
						cin >> savingsFnameMod;
						cout << "Enter a last name: ";
						cin >> savingsLnameMod;
						cin.ignore();
						cout << "Enter an address: ";
						getline(cin, savingsAddressMod);
						cout << "Enter an email: ";
						cin >> savingsEmailMod;
						cout << "Enter a phone number: ";
						cin >> savingsPhoneMod;


						CustomerMod->setAll(savingsFnameMod, savingsLnameMod, savingsAddressMod, savingsEmailMod, savingsPhoneMod);

						cout << "Customer's information has been updated!" << endl;
					}
					else if (savingChoice == 2)
					{
						int newID;
						cout << "What would you like your new ID to be: ";
						cin >> newID;

						if (newID >= 0)
						{
							savingAccount[modifyIndex].setID(newID);
							cout << "ID has been updated!" << endl;
						}
						else
						{
							cout << "Invalid ID" << endl;
						}
					}
					else if (savingChoice == 3) //updating balance
					{
						double newBalance;
						cout << "What would you like your new balance to be: ";
						cin >> newBalance;

						if (newBalance >= 0)
						{
							savingAccount[modifyIndex].setBalance(newBalance);
							cout << "Balance has been updated!" << endl;
						}
						else
						{
							cout << "Invalid Balance!" << endl;
						}

					}
					else if (savingChoice == 4) // updating interest rate
					{
						double newInterestRate;
						cout << "What would you like your new interest rate to be: ";
						cin >> newInterestRate;

						if (newInterestRate >= 0)
						{
							savingAccount[modifyIndex].setInterestRate(newInterestRate);
							cout << "Interest rate has been updated!" << endl;
						}
						else
						{
							cout << "Invalid interest rate!" << endl;
						}
					}
					else
					{
						cout << "Invalid choice!" << endl;
					}

				}
			}
			else
			{
				cout << "Not a valid option!" << endl;
			}


		}
		break;

		case 5: //delete account
			cout << "Delete Checking or Savings Account(C or S): ";
			cin >> opt;
			if (opt == 'c' || opt == 'C')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i > checkingCount; i++)
				{
					customerFound = false;
					if (checkingAccount[i].getAccountCustomer()->getLname() == lname && checkingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cout << "Are you sure you want to delete this account(y or n):" << endl;
						cin >> opt;
						if (opt == 'y' || opt == 'Y')
						{
							tempCustomer = nullptr;
							checkingAccount[i].setAll(0, 0, tempCustomer, 0);
							cout << "Account Deleted." << endl;
						}
						else if (opt == 'n' || opt == 'N')
						{
							cout << "Exiting delete option..." << endl;
							break;
						}
					}
				}
				if (customerFound == false)
					cout << "Account not found." << endl;
			}
			else if (opt == 's' || opt == 'S')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < savingsCount; i++)
				{
					customerFound = false;
					if (savingAccount[i].getAccountCustomer()->getLname() == lname && savingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cout << "Are you sure you want to delete this account(y or n):" << endl;
						cin >> opt;
						if (opt == 'y' || opt == 'Y')
						{
							tempCustomer = nullptr;
							savingAccount[i].setAll(0, 0, tempCustomer, 0);
							cout << "Account Deleted." << endl;
						}
						else if (opt == 'n' || opt == 'N')
						{
							cout << "Exiting delete option..." << endl;
							break;
						}
					}
				}
				if (customerFound == false)
					cout << "Account not found." << endl;
			}
			else
			{
				cout << "Invalid Option." << endl;
			}
			break;
		case 6://tranfer between account
		{
			char fromAccount, toAccount;
			int fromAccountID, toAccountID;
			double amountTrans;

			cout << "Would you like to transfer from a Checking account or Savings account(C or S): ";
			cin >> fromAccount;
			cout << "Enter ID for this account: ";
			cin >> fromAccountID;

			cout << "Is this money getting trasferred to a Checking account or Savings account(C or S): ";
			cin >> toAccount;
			cout << "Enter ID for this account: ";
			cin >> toAccountID;

			cout << "Enter the amount you would like to trasfer: ";
			cin >> amountTrans;

			if (amountTrans <= 0)
			{
				cout << "Invalid amount!" << endl;
				break;
			}

			Checking* fromChecking = nullptr;
			Checking* toChecking = nullptr;
			SavingAccount* fromSaving = nullptr;
			SavingAccount* toSaving = nullptr;

			if (fromAccount == 'C' || fromAccount == 'c') //searching FROM Account Checking
			{
				for (int i = 0; i < checkingCount; i++)
				{
					if (checkingAccount[i].getID() == fromAccountID)
					{
						fromChecking = &checkingAccount[i];
						break;
					}
				}

			}
			else if (fromAccount == 'S' || fromAccount == 's') //searching FROM Account Saving
			{
				for (int i = 0; i < savingsCount; i++)
				{
					if (savingAccount[i].getID() == fromAccountID)
					{
						fromSaving = &savingAccount[i];
						break;
					}
				}

			}
			else
			{
				cout << "Invalid choice!" << endl;
				break;
			}

			if (toAccount == 'C' || toAccount == 'c') //seraching TO Account Checking
			{
				for (int i = 0; i < checkingCount; i++)
				{
					if (checkingAccount[i].getID() == toAccountID)
					{
						toChecking = &checkingAccount[i];
						break;
					}
				}
			}
			else if (toAccount == 'S' || toAccount == 's') //searching TO Account Saving
			{
				for (int i = 0; i < savingsCount; i++)
				{
					if (savingAccount[i].getID() == toAccountID)
					{
						toSaving = &savingAccount[i];
						break;
					}
				}

			}
			else
			{
				cout << "Invalid choice!" << endl;
				break;
			}

			if ((fromChecking == nullptr && fromSaving == nullptr) || (toChecking == nullptr && toSaving == nullptr)) //checking if accounts have been found		
			{
				cout << "One or both accounts not found!" << endl;
				break;
			}

			if (fromAccount == toAccount && fromAccountID == toAccountID)
			{
				cout << "Cannot transfer to the same account!" << endl;
				break;
			}

			double balanceBefore;
			bool notEqual = true;

			if (fromChecking != nullptr) //performing withdrawl from account
			{
				balanceBefore = fromChecking->getBalance();
				fromChecking->withdrawMoney(amountTrans);

				if (fromChecking->getBalance() == balanceBefore)
				{
					notEqual = false;
				}
			}
			else if (fromSaving != nullptr)
			{
				balanceBefore = fromSaving->getBalance();
				fromSaving->withdrawMoney(amountTrans);

				if (fromSaving->getBalance() == balanceBefore)
				{
					notEqual = false;
				}
			}

			if (!notEqual)
			{
				cout << "Transfer failed!" << endl;
				break;
			}

			if (toChecking != nullptr) //performing transfer to account
			{
				toChecking->depositMoney(amountTrans);
				cout << "Transfer was completed!" << endl;
				t.setAll(toChecking->getAccountCustomer(), "Transfer", 'T', amountTrans);
				t.recordCheckingTransaction(t);
				t.recordAll(t);
			}
			else if (toSaving != nullptr)
			{
				toSaving->depositMoney(amountTrans);
				cout << "Transfer was completed!" << endl;
				t.setAll(toSaving->getAccountCustomer(), "Transfer", 'T', amountTrans);
				t.recordSavingsTransaction(t);
				t.recordAll(t);
			}

		}
		break;


		case 7: // deposit to saving or checking account 
			cout << "Deposit to Checking or Savings Account (C or S): ";
			cin >> opt;
			if (opt == 'C' || opt == 'c')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < checkingCount; i++)
				{
					customerFound = false;
					if (checkingAccount[i].getAccountCustomer()->getLname() == lname && checkingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cout << "Enter amount: ";
						cin >> amount;
						while (amount < 0)
						{
							cout << "Invalid. Enter positive values: ";
							cin >> amount;
						}
						checkingAccount[i].depositMoney(amount);
						cout << "Balance: " << checkingAccount[i].getBalance() << endl;
						t.setAll(checkingAccount[i].getAccountCustomer(), "Deposit", 'D', amount);
						t.recordCheckingTransaction(t);
						t.recordAll(t);
						break;
					}
				}
				if (customerFound == false)
				{
					cout << "Account not found." << endl;
				}


			}
			else if (opt == 'S' || opt == 's')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < savingsCount; i++)
				{
					customerFound = false;
					if (savingAccount[i].getAccountCustomer()->getLname() == lname && savingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cout << "Enter amount: ";
						cin >> amount;
						while (amount < 0)
						{
							cout << "Invalid. Enter positive values: ";
							cin >> amount;
						}
						savingAccount[i].depositMoney(amount);
						cout << "Balance: " << savingAccount[i].getBalance() << endl;
						t.setAll(savingAccount[i].getAccountCustomer(), "Deposit", 'D', amount);
						t.recordSavingsTransaction(t);
						t.recordAll(t);
						break;
					}
				}
				if (customerFound == false)
				{
					cout << "Account not found." << endl;
				}

			}
			break;

		case 8: // withdraw from saving or checking account 
			cout << "Withdraw from Checking or Savings Account (C or S): ";
			cin >> opt;
			if (opt == 'C' || opt == 'c')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < checkingCount; i++)
				{
					customerFound = false;
					if (checkingAccount[i].getAccountCustomer()->getLname() == lname && checkingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cout << "Enter amount: ";
						cin >> amount;
						while (amount < 0)
						{
							cout << "Invalid. Enter positive values: ";
							cin >> amount;
						}
						balance = checkingAccount[i].getBalance();
						checkingAccount[i].withdrawMoney(amount);
						cout << "Balance: " << checkingAccount[i].getBalance() << endl;
						if (balance > checkingAccount[i].getBalance())
						{
							t.setAll(checkingAccount[i].getAccountCustomer(), "Withdrawal", 'W', amount);
							t.recordCheckingTransaction(t);
							t.recordAll(t);
						}
						break;
					}
				}
				if (customerFound == false)
				{
					cout << "Account not found." << endl;
				}


			}
			else if (opt == 'S' || opt == 's')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < savingsCount; i++)
				{
					customerFound = false;
					if (savingAccount[i].getAccountCustomer()->getLname() == lname && savingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cout << "Enter amount: ";
						cin >> amount;
						while (amount < 0)
						{
							cout << "Invalid. Enter positive values: ";
							cin >> amount;
						}
						balance = savingAccount[i].getBalance();
						savingAccount[i].withdrawMoney(amount);
						cout << "Balance: " << savingAccount[i].getBalance() << endl;
						if (balance > savingAccount[i].getBalance())
						{
							t.setAll(savingAccount[i].getAccountCustomer(), "Withdrawal", 'W', amount);
							t.recordSavingsTransaction(t);
							t.recordAll(t);
						}
						break;
					}
				}
				if (customerFound == false)
				{
					cout << "Account not found." << endl;
				}

			}
			break;

		case 9: //pay bill
			cout << "From Checkingor Savings account(C or S)" << endl;
			cin >> opt;
			if (opt == 'C' || opt == 'c')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < checkingCount; i++)
				{
					customerFound = false;
					if (checkingAccount[i].getAccountCustomer()->getLname() == lname && checkingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cin.ignore();
						cout << "Enter Bill Name: ";
						getline(cin, billName);
						cout << "Enter amount: ";
						cin >> amount;
						while (amount < 0)
						{
							cout << "Invalid. Enter positive values: ";
							cin >> amount;

						}
						balance = checkingAccount[i].getBalance();
						checkingAccount[i].payBill(amount);
						if (balance > checkingAccount[i].getBalance())
						{
							t.setAll(checkingAccount[i].getAccountCustomer(), billName, 'B', amount);
							t.recordCheckingTransaction(t);
							t.recordAll(t);
						}
						break;
					}
				}
				if (!customerFound)
					cout << "Account not found" << endl;
			}
			else if (opt == 's' || opt == 'S')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < savingsCount; i++)
				{
					customerFound = false;
					if (savingAccount[i].getAccountCustomer()->getLname() == lname && savingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						cin.ignore();
						cout << "Enter Bill Name: ";
						getline(cin, billName);
						cout << "Enter amount: ";
						cin >> amount;
						while (amount < 0)
						{
							cout << "Invalid. Enter positive values: ";
							cin >> amount;
						}
						balance = savingAccount[i].getBalance();
						savingAccount[i].payBill(amount);
						if (balance > savingAccount[i].getBalance())
						{
							t.setAll(savingAccount[i].getAccountCustomer(), billName, 'B', amount);
							t.recordCheckingTransaction(t);
							t.recordAll(t);
						}
						break;
					}
				}
				if (!customerFound)
					cout << "Account not found" << endl;
			}
			else
				cout << "Invalid option" << endl;
			break;

		case 10: // add customer to approved loan list
			cout << "Enter Last Name: ";
			cin >> lname;
			cout << "Enter Email: ";
			cin >> email;
			for (int i = 0; i < checkingCount; i++)
			{
				customerFound = false;
				if (checkingAccount[i].getAccountCustomer()->getLname() == lname && checkingAccount[i].getAccountCustomer()->getEmail() == email)
				{
					customerFound = true;
					t.loanList(checkingAccount[i].getAccountCustomer());
					cout << "Customer Added to Approved loan list" << endl;
					break;
				}
			}


			for (int i = 0; i < savingsCount; i++)
			{
				customerFound2 = false;
				if (savingAccount[i].getAccountCustomer()->getLname() == lname && savingAccount[i].getAccountCustomer()->getEmail() == email)
				{
					customerFound2 = true;
					t.loanList(savingAccount[i].getAccountCustomer());
					cout << "Customer Added to Approved loan list" << endl;
					break;
				}
			}
			if (!customerFound && !customerFound2)
				cout << "Account not found" << endl;

			break;

		case 11:
		{
			char ans;
			cout << "Would you like to see only checking, saving, or all accounts(C, S, or B): ";
			cin >> ans;
			if (ans == 'C' || ans == 'c')
			{
				cout << "Checking Accounts: " << endl;
				checkingAccount->printHeader();
				for (int i = 0; i < checkingCount; i++)
				{
					checkingAccount[i].printInfo();

				}
			}
			else if (ans == 'S' || ans == 's')
			{
				cout << "Savings Accounts: " << endl;
				savingAccount->printHeader();
				for (int i = 0; i < savingsCount; i++)
				{
					savingAccount[i].printInfo();
				}
			}
			else if (ans == 'B' || ans == 'b')
			{
				cout << "Checking Accounts: " << endl;
				checkingAccount->printHeader();
				for (int i = 0; i < checkingCount; i++)
				{
					checkingAccount[i].printInfo();
					
				}
				cout << endl << endl;
				cout << "Savings Accounts: " << endl;
				savingAccount->printHeader();
				for (int i = 0; i < savingsCount; i++)
				{
					savingAccount[i].printInfo();
				}
				
			}
			else
			{
				cout << "Invalid option!" << endl;
				
			}
			break;
		}

			
		case 12:// show transaction history using files& user validation
			cout << "Checking, Savings(C or S): " << endl;
			cin >> opt;
			if (opt == 'C' || opt == 'c')
			{

				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < checkingCount; i++)
				{
					customerFound = false;
					if (checkingAccount[i].getAccountCustomer()->getLname() == lname && checkingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						t.showCheckingHistory(checkingAccount[i].getAccountCustomer());
						break;
					}
				}
				if (!customerFound)
				{
					cout << "Account not found!" << endl;
				}
			}
			else if (opt == 's' || opt == 'S')
			{
				cout << "Last Name: ";
				cin >> lname;
				cout << "Email: ";
				cin >> email;
				for (int i = 0; i < savingsCount; i++)
				{
					customerFound = false;
					if (savingAccount[i].getAccountCustomer()->getLname() == lname && savingAccount[i].getAccountCustomer()->getEmail() == email)
					{
						customerFound = true;
						t.showSavingsHistory(savingAccount[i].getAccountCustomer());
						break;
					}
				}
				if (!customerFound)
				{
					cout << "Account not found!" << endl;
				}

			}
			else
			{
				cout << "Invalid option!" << endl;
				
			}
			break;

		default:
			cout << "Invalid option" << endl;
			cout << "Enter option: ";
			cin >> ans;
			break;
		}
		


			system("pause");
			system("cls");

			cout << "Please Choose from the list of options below: " << endl << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "1- Create Checking Account" << endl;
			cout << "2- Create Savings Account" << endl;
			cout << "3- View Account Information" << endl;
			cout << "4- Modify Account" << endl;
			cout << "5- Delete Account" << endl;
			cout << "6- Transfer Between Accounts" << endl;
			cout << "7- Deposit Money" << endl;
			cout << "8- Withdraw Money" << endl;
			cout << "9- Pay Bill" << endl;
			cout << "10- Add Customer to approved loan list" << endl;
			cout << "11- Print All Account Info" << endl;
			cout << "12- Show Transaction History" << endl;
			cout << "13- Exit Program" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "Enter option: ";
			cin >> ans;

	}
		cout << "Exiting Program...." << endl;

		system("pause");
		return 0;

}