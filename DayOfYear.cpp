/*****************************************************
* FILENAME : DayOfYear.cpp
*
* DESCRIPTION : In Class Activity Assignment dealing with
* operator overloading and static member variables.
*
* AUTHOR :  Amir Sotoodeh
* START DATE : 5/1/18
*
******************************************************/

#include <stdafx.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
static string date;

class DayOfYear
{
private:
	int Day;
	int countDay = 0;
	static string Month[];
	int MonthDayCounts[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	DayOfYear(int enteredDay) {
		if (enteredDay > 0 || enteredDay <= 365) {
			Day = enteredDay;
		}
		else {
			exit(0);
		}
	}
	DayOfYear(string monthName, int day) {
		int index = 0;
		int position = -1;
		bool found = false;

		while (index < 12 && !found)
		{
			if (Month[index] == monthName)
			{
				found = true;
				position = index;
			}
			index++;
		}
		if (found == false)
		{
			cout << "Please enter a valid month.\n";
			exit(0);
		}


		if (day > MonthDayCounts[position] || day < 0)
		{
			cout << "Invalid number of a days!!\n"
				<< monthName << " only has " << MonthDayCounts[position] << " days." << endl;
			exit(0);
		}
		else
		{
			for (int i = 0; i < position; i++)
			{
				countDay += MonthDayCounts[i];
			}

			Day = countDay + day;
		}
	}
	void print();

	DayOfYear operator ++ (); //PREFIX PROTOTYPE
	DayOfYear operator ++ (int); //POSTFIX PROTOTYPE
	DayOfYear operator -- (); //PREFIX PROTOTYPE
	DayOfYear operator -- (int); //POSTFIX PROTOTYPE

};

DayOfYear DayOfYear::operator++() //OVERLOAD PREFIX (DEFINITION)
{
	if (Day == 365)
		Day = 1;
	else
		Day++;
	return *this;
}


DayOfYear DayOfYear::operator++(int) //OVERLOAD POSTFIX (DEFINITION)
{
	if (Day == 365)
		Day = 1;
	else
		Day++;
	return *this;
}

DayOfYear DayOfYear::operator--() //OVERLOAD PREFIX (DEFINITION)
{
	if (Day == 1)
		Day = 365;
	else
		Day--;
	return *this;
}

DayOfYear DayOfYear::operator--(int) //OVERLOAD POSTFIX (DEFINITION)
{
	if (Day == 1)
		Day = 365;
	else
		Day--;
	return *this;
}

void DayOfYear::print()
{
	int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int start = 0, month, day;

	//arithmetic logic found online
	for (int i = 0; i < 12; i++)
	{
		if (Day < (start + (Months[i] + 1)))
		{
			month = i;
			day = Day - start;
			break;
		}

		start += Months[i];
	}

	cout << Month[month] << " " << day << endl;
}

//Must define static variables outside of constructor.
string DayOfYear::Month[] = { "January", "February", "March", "April", "May", "June", "July",
"August", "September", "October", "November", "December" };

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);


	string monthName;
	int userDay;

	cout << "Demonstrating #2 Constructor" << endl;
	cout << "Enter a day (0-365): " << endl;
	cin >> userDay;

	DayOfYear Day(userDay);
	Day.print();

	cout << endl << "Demonstrating #3 Constructor and Operator Overload" << endl;
	cout << "Enter month (string) and day (int) separated by a space: " << endl;
	cin >> monthName;
	cin >> userDay;

	DayOfYear Day2(monthName, userDay);

	Day2.print();

	cout << "Calling Overloaded ++ Prefix: ";
	++Day2;
	Day2.print();

	cout << "Calling Overloaded ++ Postfix: ";
	Day2++;
	Day2.print();

	cout << "Calling Overloaded -- Prefix : ";
	--Day2;
	Day2.print();

	cout << "Calling Overloaded -- Postfix : ";
	Day2--;
	Day2.print();

	return 0;
}
