#include "../std_lib_facilities.h"





int main() {
	
	try{

	vector<int> v;

	for (int x; cin >> x;)
		
	{
		x.push_back(x);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << "v[" <<i << "] == " <<v[i] << endl;
	}



	return 0;
	}
	catch(push_back) {
	cout << "push_back" << endl;
	return 2;
	}
	
	catch(...){
	cout << "Erruption, something went wrong" << endl;
	return 3;
	}
}