#include "stdafx.h"
#include <cstdio>
#include <string>

using namespace std;

class Employee {

	string name;
	int idNumber;
	string department;
	string position;

public:

	Employee(string n2, int id2, string d, string p) {
		name = n2;
		idNumber = id2;
		department = d;
		position = p;
	}

	Employee(string n2, int id2) {
		name = n2;
		idNumber = id2;
		department = "";
		position = "";
	}

	Employee() {
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}

	void setName(string n) { name = n; }
	string getName() { return name; }

};



int main(int argc, char ** argv) {


}
