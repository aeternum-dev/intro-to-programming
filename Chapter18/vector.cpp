#include "../std_lib_facilities.h"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> a) {
	vector<int> lv; //a.size() elem legyen
	lv = gv;

	cout << "elements of gv2: " << endl; 
	for (int i = 0; i < 10; ++i)
	{
		cout << lv[i] << endl;
	}

	vector<int> lv2 = a;


	cout << "elements of lv2: " << endl; 
	for (int i = 0; i < a.size(); ++i)
	{
		cout << lv2[i] << endl;
	}

	return;

}

int main() {

	f(gv);

	vector<int> vv = {1,2,6,24,120,720,5040,40320,362880,3628800};

	f(vv);




	return 0;
}
