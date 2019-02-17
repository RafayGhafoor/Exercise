#include <iostream>
#include <conio.h>

using namespace std;
int bignumber(int number1, int number2, int number3);

int main()
{
	int number1=0; cout <<"number 1 " <<endl; cin >> number1;
	int number2=0; cout <<"number 2 " <<endl; cin >> number2;
	int number3=0; cout <<"number 3 " <<endl; cin >> number3;
	int big=0;
	big= bignumber(number1,number2,number3);
	cout << big;
	getch();
	return 0;

	

}
	
int bignumber(int number1, int number2, int number3)
	{
	int big=0;	
	if (number1>=number2 && number1>=number3)
		big = number1;
	else if (number2>=number1 && number2>=number3)
		big = number2;
	else 
		big = number3;
	return big;

	}