#include "../std_lib_facilities.h"


//1. feladat
int ga [10]={1,2,4,8,16,32,64,128,256,512};

//2. & 3. feladat
void f(int a[], int n) {
	int la[10];



	for (int i = 0; i < 10; ++i) {
		la[i] = ga[i];
	}

	for (int i = 0; i < n; ++i){
		cout << la[i] << endl;
	}	
	
	int* p = new int[n];

	for (int i = 0; i < n; ++i){
		p[i] = a[i];
	}	
	
	for (int i = 0; i < n; ++i) {
		cout << p[i] << endl;
	}

	delete[] p;

	return;
	
}


//4. feladat
int main() {

	f(ga,10);

	int aa [10]={1,2,6,24,120,720,5040,40320,362880,3628800};
	f(aa,10); 


	return 0;
}