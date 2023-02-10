//8. feladat
#include "../std_lib_facilities.h"

double convert(double value, string unit) {
    constexpr double cm_to_m = (1.0/100);
    constexpr double in_to_m = (1.0/0.0254);
    constexpr double ft_to_m = (1.0/0.3048);

    if (unit == "m"){
        return value;}
    else if (unit == "cm"){
        return (value*cm_to_m);}
    else if (unit == "in"){
        return (value*(2.54/100));}
    else if (unit == "ft"){
        return (value*(30.48/100));}
    else {error("Invalid unit!/unit not entered!");}
    
}

int main() {
	
	string num_str = ""; 
    string unit;
	double small;
	double large;
    bool isfirst = true;


	while (true) {
		cout << "\nPlease enter a number with a unit:\n";

		cin >> num_str >> unit;
		if (num_str == "|" || unit == "|") {
			break;
        }
		else {
            double num = convert(stod(num_str),unit); //handled in m
            if(isfirst == true) {
                small = num;
                large = num;
                isfirst = false;
            }
            cout << endl << num_str << ' ' << unit << endl;
            
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