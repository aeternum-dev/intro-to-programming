#include "../std_lib_facilities.h"

int main() {
	
	vector <double> temps;
	
	for(double temp; cin >> temp;) {
		
		temps.push_back(temp);	
		
	}	 
	
	for (auto temp : temps) {
		
		cout << temp << endl;
	
	}
	
	double sum = 0;
	
	for(double temp : temps) {
		sum += temp;
		
	}
	
	cout << "Avg temp: " << sum / temps.size();
	
	sort(temps) ;
	
	for(auto temp: temps)
		cout << temp <<endll;
		
	cout << "Median temps :" << temps[temps.size()/2] << endl;
	
	return 0;

}
