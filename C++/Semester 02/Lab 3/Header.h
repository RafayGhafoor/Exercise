#include <iostream>

using namespace std;

class DateType
{
  private:
	int day;
	int month;
	int year;

  public:
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();
	void setDate();
	void resetDate();
	void printDate();
};
// day cannot be greater than 31 etc