#include "../std_lib_facilities.h"

int main() {
	
	
	vector <int> v = {4, 7, 2, 8, 9};
	
	for(int i = 0; i < v.size(); i++) {
		 cout << v[i] << endl;
	}
	
	
	vector <string> names = {"Pisti", "Dani", "Bazsi"};
	
	for (string name: names) {
		cout << name << endl;
	}
	
	
	vector <double> dv;
	
	cout << dv.size() << endl;
	
	dv.push_back(2.7);
	dv.push_back(5.887);
	dv.push_back(5);
	
	cout << dv.size() << endl;
	
	for (auto number : dv) {
		cout << number << endl;
	}
	
	return 0;

}
