//6. feladat
#include "../std_lib_facilities.h"

int main() {
	
	string num_str = ""; 
	double small;
	double large;
    bool isfirst = true;
	

	while (true) {
		cout << "\nPlease enter a number:\n";

		cin >> num_str;
		if (num_str == "|")
			break;
		else {
            double num = stod(num_str);
            if(isfirst == true) {
                small = num;
                large = num;
                isfirst = false;
            }
            cout << endl << num << endl;
            
            if (num <= small) {
                small = num;
                cout << "the smallest so far" << endl;
            }
            if (num >= large) {
                large = num;
                cout << "the largest so far" << endl;
            }
        }
	}
		
	return 0;
}