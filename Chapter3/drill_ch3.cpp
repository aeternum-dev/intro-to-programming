#include "../std_lib_facilities.h"

int main() {
	
	int age;
	char friend_sex = '0';
	string first_name, friend_name, friend2_name;
	
	//1.
	cout << "Enter your first name: ";
	cin >> first_name;
	cout << "Hello, " << first_name << "\n\n" ;
	
	cout << "Enter the name of the person you want to write to: " ;
	cin >> friend_name;
	cout << "\nDear " << friend_name << ",\n";
	
	//2.
	cout << "How are you? I am fine. I miss you.\nAkcios a mateking. Puszi szia.\n\n" ;
	
	//3.
	cout << "Enter the name of your mutual friend: " ;
	cin >> friend2_name;
	
	cout << "Have you seen " << friend2_name << " lately?\n" ;
	
	//4.
	cout << "\nEnter the sex of the mutual friend (m/f): " ;
	cin >> friend_sex; 
	
	if 	(friend_sex == 'm') {
		cout << "If you see " << friend2_name << " please ask him to call me.\n" ;
		}
		
	else if (friend_sex == 'f') {
		cout << "If you see " << friend2_name << " please ask her to call me.\n" ;
		}
	else {
		cout << "If you see " << friend2_name << " please ask them to call me.\n" ;
		}
	
	//5.
	cout << "\nPlease, enter an age: ";
	cin >> age;
	cout << "I hear you just had a birthday and you are " << age << " years old." <<endl ;
	
	if (age <= 0 || age >= 110) {
		simple_error("you're kidding!");
	}
	
	//6.
	if 	(age < 12) {
		cout << "Next year you will be " <<age+1 << '\n';
		}
		
	else if (age == 17) {
		cout << "Next year you will be able to vote.\n" ;
		}
		
	else if (age > 70) {
		cout << "I hope you are enjoying retirement.\n" ;
		}
	
	//7.
	cout << "\nYours sincerely,\n\n\nAetherns\n";
	
	
	return 0;
	
}
