#include <iostream>

using namespace std;

void cal_big_num(int num1, int num2, int num3, int& big_num);

int main () {
    int big_num=0;	
    cal_big_num(1,7,3, big_num);
    cout << big_num << endl;

}

void cal_big_num(int num1, int num2, int num3, int& big_num) {
	if (num1>=num2 && num1>=num3)
		big_num = num1;
	else if (num2>=num1 && num2>=num3)
		big_num = num2;
	else 
		big_num = num3;
}