#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() { 
	int num; cout << "Please enter a number: "; cin >> num;
	int seq = 1, i = 2;
	bool is_triangular = false;
	while (num >= seq) {
		if (num == seq) { 
			is_triangular = true;
			break;
		}
		seq += i;	
		i += 1;
		
	}
	if (is_triangular) cout << "\nThe number is triangular\n";
	else cout << "\nThe number is not triangular\n\n";
	system("pause");
}
