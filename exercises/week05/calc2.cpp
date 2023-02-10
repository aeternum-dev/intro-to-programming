#include "../std_lib_facilities.h"


int main() {
	cout << "Please enter an expression\n" ;
    cout << "please enter an x to the end of theexpression\n" ;

	int lvar = 0, rvar = 0;
	
    cin >> lvar;
    if(!cin) error("No lvar");

    for (char op; cin >> op;) {
        if(op != 'x')cin >> rvar;
        if(!cin) error("No rvar");

        switch (op)
        {
        case '+' :
            lvar += rvar;
            break;
        case '-' :
            lvar -= rvar;
        case '*' :
            lvar *= rvar;
        case '/' :
            lvar /= rvar;
        default:
            cout << "Result: " << lvar << rvar;
            break;
        }
    }
    
    error("Bad expression!");

	return 0;

}

