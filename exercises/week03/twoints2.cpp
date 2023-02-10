#include "../std_lib_facilities.h"

int main() {
	int a , b = 0;
	
	const double cm_per_inch = 2.54;
	
	double lenght = -1;
	char unit = 0;
	
	cout << "please enter a lenght followed by a unit (c or i):\n" ;
	
	cin >> lenght >> unit;
	
	/*if (unit == 'i')
		cout << lenght << "in == " << lenght*cm_per_inch << " cm " << endl;
	else if (unit == 'c')
		cout << lenght << "cm == " << lenght*cm_per_inch << " inch " << endl;
	else 
		cout << "Error, not valid character!" << endl; */
		
	switch (unit) {
		case 'i':
			cout << lenght << "in == " << lenght*cm_per_inch << " cm " << endl;
			break;
		case 'c':
			cout << lenght << "in == " << lenght*cm_per_inch << " cm " << endl;
			break;
		deafult:
			cout << "Error, not valid character!" << endl;
			
		 
	
	return 0;

}
