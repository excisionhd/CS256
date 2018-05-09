/*****************************************************
* FILENAME : PrefCustomer.cpp
*
* DESCRIPTION :
*       ICA dealing with Classes and Inheritance
*
* AUTHOR :  Amir Sotoodeh
* START DATE : 5/8/18
*
******************************************************/
#include "stdafx.h"
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

// Base class
class PersonData {
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	string zip;
	string phone;

public:
	PersonData() {};
	PersonData(string l, string f, string a, string c, string s, string z, string p) {
		lastName = l;
		firstName = f;
		address = a;
		city = c;
		state = s;
		zip = z;
		phone = p;
	}
	string getLastName() {
		return lastName;
	}
	string getFirstName() {
		return firstName;
	}
	string getAddress() {
		return address;
	}
	string getCity() {
		return city;
	}
	string getState() {
		return state;
	}
	string getZip() {
		return zip;
	}
	string getPhone() {
		return phone;
	}
	void setLastName(string s) {
		lastName = s;
	}
	void setFirstName(string s) {
		firstName = s;
	}
	void setAddress(string s) {
		address = s;
	}
	void setCity(string s) {
		city = s;
	}
	void setState(string s) {
		state = s;
	}
	void setZip(string s) {
		zip = s;
	}
	void setPhone(string s) {
		phone = s;
	}


};

class CustomerData : public PersonData {
	private:
		int customerNumber;
		bool mailingList;
	public:
		CustomerData() {};
		CustomerData(int i, bool b) {
			customerNumber = i;
			mailingList = b;
		};
		void printMailing() {
			if (mailingList == true)
				cout << this->getFirstName() << " " << this->getLastName() << " is subscribed to the mailing list!"<<endl;
			else
				cout << this->getFirstName() << " " << this->getLastName() << " is not subscribed to the mailing list."<<endl;
		}
		int getCustomerNumber() {
			return customerNumber;
		}
		bool getMailingList() {
			return mailingList;
		}
		void setCustomerNumber(int i) {
			customerNumber = i;
		}
		void setMailingList(bool b) {
			mailingList = b;
		}
};

class PreferredCustomer : public CustomerData {
	private:
		double purchasesAmount;
		double discountLevel;
	public:
		PreferredCustomer() {};
		PreferredCustomer(double p, double d) {
			purchasesAmount = p;
			discountLevel = d;
		}
		PreferredCustomer(double p) {
			purchasesAmount = p;
			if (p < 0) {
				cout << "Invalid input for sales number." << endl;
				exit(0);
			}
			if (p >= 500 && p < 1000) {
				discountLevel = 0.05;
			}
			else if (p >= 1000 && p < 1500) {
				discountLevel = 0.06;
			}
			else if (p >= 1500 && p < 2000) {
				discountLevel = 0.07;
			}
			else if (p >= 2000) {
				discountLevel = 0.1;
			}
			else {
				discountLevel = 0;
			}
		}
		void updateDiscount() {
			if (purchasesAmount >= 500 && purchasesAmount < 1000) {
				discountLevel = 0.05;
			}
			else if (purchasesAmount >= 1000 && purchasesAmount < 1500) {
				discountLevel = 0.06;
			}
			else if (purchasesAmount >= 1500 && purchasesAmount < 2000) {
				discountLevel = 0.07;
			}
			else if (purchasesAmount >= 2000) {
				discountLevel = 0.1;
			}
			else {
				discountLevel = 0;
			}
		}
		void print() {
			cout << this->getFirstName() << " " << this->getLastName() << " bought "<< purchasesAmount <<" items and receives a " << discountLevel * 100 << "% discount!" << endl;
		}
		void setPurchasesAmount(double p) {
			purchasesAmount = p;
			updateDiscount();
		}
		void setDiscount(double d) {
			discountLevel = d;
		}
		double getPurchasesAmount() {
			return purchasesAmount;
		}
		double getDiscountLevel() {
			return discountLevel;
		}

};


int main() {
	cout << "Classes and Inheritance Demonstration" << endl;
	cout << "-------------------------------------" << endl;
	CustomerData c1(10212, true);
	c1.setFirstName("Robert");
	c1.setLastName("Lee");
	c1.printMailing();
	CustomerData c2(10213, false);
	c2.setFirstName("Joe");
	c2.setLastName("Lee");
	c2.printMailing();
	PreferredCustomer p1(500);
	p1.setFirstName("Bob");
	p1.setLastName("Smith");
	p1.print();
	PreferredCustomer p2(1500);
	p2.setFirstName("James");
	p2.setLastName("Smith");
	p2.print();
	PreferredCustomer p3(2000);
	p3.setFirstName("Jane");
	p3.setLastName("Smith");
	p3.print();
	PreferredCustomer p4(2);
	p4.setFirstName("Tony");
	p4.setLastName("Diaz");
	p4.print();
	PreferredCustomer p5(230);
	p5.setFirstName("Seth");
	p5.setLastName("Rogan");
	p5.print();
	cout << "After buying more items..." << endl;
	p5.setPurchasesAmount(600);
	p5.print();

	return 0;
}
