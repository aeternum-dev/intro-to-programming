include "myheader.h"
include "../../std_lib_facilities.h"

void f (int x ) {
	int z = x + 7;
	x+= 10;
	cout << "fben z értéke" << z << endl;
	cout << "fben  y értéke" << z << endl;


int main() {
	int z  = 10 ;
	cout << "Z értéke mainben" <<z << endl;
	f(z);
	cout << "Z értéke mainben másodszor" <<z << endl;
	int x = g(z) ;
	cou << "x értéke a mainben" << x << endl;
	return 0;
}
