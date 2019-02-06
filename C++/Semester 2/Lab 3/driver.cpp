#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	DateType d1;

	cout << "Press 0 to quit" << endl;
	cout << "Press 1 for setDay" << endl;
	cout << "Press 2 for setMonth" << endl;
	cout << "Press 3 for setYear" << endl;
	cout << "Press 4 for getDay" << endl;
	cout << "Press 5 for getMonth" << endl;
	cout << "Press 6 for getYear" << endl;
	cout << "Press 7 for setDate" << endl;
	cout << "Press 8 for resetDate" << endl;
	cout << "Press 9 for PrintDate" << endl;

	int i = 1;
	while (i != 0)
	{
		cin >> i;

		if (i == 1)
			d1.setDay(0);
		if (i == 2)
			d1.setMonth(0);
		if (i == 3)
			d1.setYear(0);
		if (i == 4)
			cout << d1.getDay() << endl;
		if (i == 5)
			cout << d1.getMonth() << endl;
		if (i == 6)
			cout << d1.getYear() << endl;
		if (i == 7)
			d1.setDate();
		if (i == 8)
			d1.resetDate();
		if (i == 9)
			d1.printDate();
		cout << "enter value again" << endl;
	}
}