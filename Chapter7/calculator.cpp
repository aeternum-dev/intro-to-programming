
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"  //header fájl importálás



//fontos osztályok létrehozása: Token, Token_stream
class Token {	
public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	//új konstruktor 
	Token(char ch, string n) :kind(ch), name(n) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { } //lehet h full(false)

	Token get();
	void unget(Token t) { buffer = t; full = true; } //vhogy át lehetne nevezni

	void ignore(char);
};

//token fajták
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char squareroot = 's';
const char power = 'p'; 


//függvények, amik a Token_stream namespace-re hagyatkoznak

//bekéri a tokent, és meghatározza annak fajtáját
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	//literálok, amik önmagukban is tokent tudnak alkotni
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case let:
		return Token(ch);
	//literálok, amikhez a number konstatns
	//is kell, hogy tokent tudjanak alkotni
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			//s = ch helyett s += ch, így a char hozzáadódik a stringhez
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			if (s == "sqrt") return Token(squareroot);
			if (s == "pow") return Token(power);
			if (s == "exit") return Token(quit); //itt valami
			return Token(name, s);
		}
		error("Bad token");
	}
}

//figyelmen kívül hagyja az inputot míg nincs meg c
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}
//Struct majdnem class, csak minden deafult public
struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; //ts nevű, Token_stream tipusú változó

double expression();

double sqrt_pow(char c)
// kiértékeli a c funkcióját. A következő bemenetnek Expression-nek kell lennie 
{
    vector<double> args;    // egy vektor az argumentumok tárolására 
                        
    Token t = ts.get();
    if (t.kind != '(') error("Definition is not correctly written");

    
    switch (c) {
    case squareroot:
        args.push_back(expression());
        break;
    case power:
        args.push_back(expression());
        t = ts.get();
        if (t.kind != ',') error("Definition is not correctly written");
        args.push_back(expression());
        break;
    }

    t = ts.get();
    if (t.kind != ')') error("Definition is not correctly written");

    // kiértékelés korlátozások megadása
    switch (c) {
    case squareroot:
        if (args[0] < 0) error("sqrt() is undefined for negative numbers");
        return sqrt(args[0]);
    case power:
        return pow(args[0], narrow_cast<int>(args[1]));
    }
}

double primary() //zárójelekkel és negatív 
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	return d;
	}
	case '-':
		return -primary();
	case '+':
		return +primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case squareroot:
		return sqrt_pow(t.kind);
	case power:
    	return sqrt_pow(t.kind);
	default:
		error("primary expected");
	}
}

double term() //a szorzást, az osztást és a modulo-t kezeli
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left = fmod(left, d); 
			break;
		}

		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression() //Az öszeadást és a kivonást kezeli
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {

	names.push_back(Variable("k", 1000)); //5. feladat; names vektor bővítése

	calculate();  //itt kedzük meghívni a main-en kívüli függvényeket 
	return 0;
}
catch (exception& e) { //itt meghatározott hibák
	cerr << "exception: " << e.what() << endl;
	return 1;
}
catch (...) { //minden egyéb hiba
	cerr << "exception\n";
	return 2;
}
