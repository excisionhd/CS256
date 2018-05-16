#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Human {
private:
	string name;
	int age;
	char sex;
	Human() {
		name = "";
		age = 0;
		sex = ' ';
	}
public:
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	char getSex() {
		return sex;
	}
	void setName(string n) {
		name = n;
	}
	void setAge(int a) {
		age = a;
	}
	void setSex(char s) {
		sex = s;
	}
	virtual string work()=0;
	friend class Child;
	friend class Parent;
protected:
	Human(string n, int a, char s) {
		name = n;
		a = age;
		sex = s;
	}

};

class Child;

class Parent : public Human {
private:
	vector<Child> children;
public:
	Parent() : Human() {}
	Parent(string n, int a, char s) { name = n; age = a; sex = s; }
	vector<Child> getChildren() {
		return children;
	}
	void setChildren(vector<Child> c) {
		children = c;
	}
	void changeName(Child& c, string NewName);
	virtual string work() override {
		if (this->name == "Homer") {
			return "Safety Inspector";
		}
		else if (this->name == "March") {
			return "Housewife";
		}
	}
};

class Child : public Human {
private:
	Parent mom;
	Parent dad;
	Child() {}
public:
	Child(Parent m, Parent d) : mom(m), dad(d) {}

	virtual string work() override {
		if (this->name == "Lisa" || this->name == "Bart") {
			return "Student";
		}
		else if (this->name == "Maggie") {
			return "Play";
		}
	}
};

void Parent::changeName(Child& c, string newName) {
	c.name = newName;
}




int main()
{
	Parent homer("Homer", 36, 'M');
	Parent march("March", 34, 'F');
	Child lisa(march, homer);
	Child bart(march, homer);
	Child maggie(march, homer);
	march.changeName(maggie, "Maggie");
	homer.changeName(bart, "Bart");
	homer.changeName(lisa, "Lisa");
	lisa.setAge(12);
	bart.setAge(10);
	maggie.setAge(3);
	lisa.setSex('F');
	bart.setSex('M');
	maggie.setSex('F');

	vector<Child> homerAndMarchChildren = { lisa, bart, maggie };
	homer.setChildren(homerAndMarchChildren);
	march.setChildren(homerAndMarchChildren);

	cout << homer.getName() << endl;
	cout << homer.getAge() << endl;
	cout << homer.getSex() << endl;
	cout << homer.work() << endl << endl;

	cout << march.getName() << endl;
	cout << march.getAge() << endl;
	cout << march.getSex() << endl;
	cout << march.work() << endl << endl;

	for (int i = 0; i < homerAndMarchChildren.size(); i++) {
		cout << homerAndMarchChildren[i].getName() << endl;
		cout << homerAndMarchChildren[i].getAge() << endl;
		cout << homerAndMarchChildren[i].getSex() << endl;
		cout << homerAndMarchChildren[i].work() << endl << endl;
	}


    return 0;
}
