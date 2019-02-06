#include "Header.h"
#include <iostream>

using namespace std;

void DateType::setDay(int day1)
{

	do
	{
		cout << " Enter the number of the day" << endl;
		cin >> day;
		if (day > 31 || day < 1)
			cout << "Error! Please enter correct day of month" << endl;
	} while (day > 31 || day < 1);
}

void DateType::setMonth(int month1)
{
	do
	{
		cout << " Enter the month of the year" << endl;
		cin >> month;
		if (month < 1 || month > 12)
			cout << "Error! Please enter correct month of year" << endl;
	} while (month < 1 || month > 12);
}

void DateType::setYear(int year1)
{

	cout << "Enter the year" << endl;
	cin >> year;
}

int DateType::getDay() { return day; }

int DateType::getMonth() { return month; }

int DateType::getYear() { return year; }

void DateType::setDate()
{
	do
	{
		cout << "Enter the number of day" << endl;
		cin >> day;
		if (day > 32 || day < 1)
			cout << "Error! Please enter correct number of day" << endl;
	} while (day > 32 || day < 1);

	do
	{
		cout << " Enter the month of the year" << endl;
		cin >> month;
		if (month < 1 || month > 12)
			cout << "Error! Please enter correct month of year" << endl;
	} while (month < 1 || month > 12);

	cout << "Enter the year" << endl;
	cin >> year;
}

void DateType::resetDate()
{
	day = 0;
	month = 0;
	year = 0;
}

void DateType::printDate()
{
	cout << "Date is" << endl;
	cout << day << "/" << month << "/" << year << endl;
}