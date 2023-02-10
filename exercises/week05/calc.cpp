#include "../std_lib_facilities.h"


int main() {
	cout << "Please enter an expression\n" ;

	int lvar = 0, rvar = 0;
	char op = 0;

	int res;
	cin >> lvar >> rvar;
	if (op == '+')
		res = lvar + rvar;

	else if (op == '-')
		res = lvar - rvar;

	cout << "Result: " << res <<endl;

	return 0;

}

