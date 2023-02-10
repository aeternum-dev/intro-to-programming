#include "std_lib_facilities.h"



int main() {
	int i = 7;
	cout <<"i: " << i << endl;
	
	int &r = i;
	cout <<"i: " << i << endl;
	cout <<"r: " << r << endl;
	
	i = 10;
	cout <<"i: " << i << endl;
	cout <<"r: " << r << endl;
	
	
	const int &c = r;
	//c = 100;
	cout <<"i: " << i << endl;
	cout <<"r: " << r << endl;
	cout <<"c: " << i << endl;
	
	
	
	
	
	return 0;
}

