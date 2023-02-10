//2. feladat
#include "../std_lib_facilities.h"

int main() {
	
	string num1_str = ""; 
	string num2_str = "";
	

	while (true) {
		cout << "Please enter two numbers:\n";

		cin >> num1_str;
		if (num1_str == "|")
			break;
		else {
			cin >> num2_str;
			if (num2_str == "|")
				break;
			else {
				
				int num1 = stoi(num1_str);
				int num2 = stoi(num2_str);
				
				if (num2 < num1) {
					cout << "The smaller value is:\t" << num2 << '\n' ;
					cout << "The larger value is:\t" << num1 << '\n' ;
					}
				else  {
					cout << "The smaller value is:\t" << num1 << '\n' ;
					cout << "The larger value is:\t" << num2 << '\n' ;
					}
				}
			}
		}
		
	return 0;
}
