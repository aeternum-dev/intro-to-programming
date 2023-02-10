#include "../std_lib_facilities.h"

int f(int);


int main() {


	
	int i = 2;
	cout << f(i)<< endl; 
	return 0;
	
}

int f(int x) {
	return x*2;
}