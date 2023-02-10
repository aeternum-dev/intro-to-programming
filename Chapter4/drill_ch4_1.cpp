//1. feladat
#include "../std_lib_facilities.h"

int main() {
	
	string num1, num2;

	
	while (true) {
		cout << "Please enter two numbers:\n";

		cin >> num1;
		if (num1 == "|")
			break;
		else
			cin >> num2;
			if (num2 == "|")
				break;
			else
			cout << num1 << ' ' << num2 << '\n';
	}

	return 0;
}
