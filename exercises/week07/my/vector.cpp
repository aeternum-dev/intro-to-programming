#include "std_lib_facilities.h"

void print(vector <double> v) {
	cout <<'{'<<endl;
	for (int i = 0; i < v.size(); i++){
	cout << v[i];
	if(i != v.size()-1)
		cout << ", "<<endl;
	
	}
	cout <<"}/n";
	 
}

int main() {
	int x = numeric_limits<int>::max();



	vector <double> vd1(10);
	vector  <double> vd2(100000);
	vector  <double> vd3(x);
	print(x);
	return 0;
}

