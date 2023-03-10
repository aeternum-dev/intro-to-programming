#include "../std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
        Token (char ch): kind(ch), value(0){}
        Token (char ch, double(val), kind(ch), value(val){}

}


Token get_token(){
    char ch;
    cin >> ch;


    switch (ch)
    {
    case '(' :
    case ')' :
    case '+' :
    case '-' :
    case '*' :
    case '/' :
    case '%' :
        return Token(ch);
    case '.': case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7': case '8':
    case '9': {
        cin.put_back(ch)
    }
    
    
    default:
        break;
    }

}

double primary() {


    Token t = get_token();
    switch(t.kind) {
        case '(' : {}
            double d = expression();
            t = get_token();
            if(t.kind != ')') error ("error ')' is missing");
                return d;}



    }
}


double term () {
    double left = primary();
    Token t = get.token();
    while(true){
         switch(t.kind){
            case '*' :
                left += primary();
                t = get.token()
                break;
            case '/' : {
                double
                if(d==0) error ("Divided by zero!");
                left /= d;
                t = get_token();
                break;
            }
            case '%' :
                left %= primary();
                t = get.token()
                break;
            deafult;
            
         }
    }
}


double expression() {
    double left = term();
    Token t = get_token();
    while(true){
        switch(t.kind){
            case '+' :
                left += term();
                t = get_token()
                break;
            case '+' :
                left += term();
                t = get.token()
                break;
            deafult :
                return left;
        }

    }
}

int main() {
	
    try{
        while(cin){
            cout << expression() << endl;

        }

    



	return 0;}
    catch (exception& e){
        cerr << e.what() << endl;
        return 1;

    }
    catch(...){
        cout << exception << endl;
        return 2;
    }

}

