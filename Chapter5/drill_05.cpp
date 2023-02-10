#include "../std_lib_facilities.h"

int main()
try {
          cout << "Success!\n";
          keep_window_open();
          return 0;
}
catch (exception& e) {
          cerr << "error: " << e.what() << '\n';
          keep_window_open();
          return 1;
}
catch (...) {
          cerr << "Oops: unknown exception!\n";
          keep_window_open();
          return 2;
}
/*
1. feladat
Cout << "Success!\n"; | cout << "Success!\n";
Nagy C, szintaxis hiba.

2. feladat
cout << "Success!\n; | cout << "Success!\n";
Lemaradt egy ", ami szintaxis hiba.

3. feladat
cout << "Success" << !\n" | cout << "Success" << "!\n";
Lemaradt egy " és egy ;, szintaxis hiba.

4. feladat
cout << success << '\n'; | cout << "Success" << '\n';
a success nem egy változó, hanem string, ezért kell "". 

5. feladat
string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
Nem tárolhatunk stringet egy int tipusú vektorban. Rossz tipusadás.

6. feladat
vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";			
vector<int> v(10); v[5] = 7; if (v[5]=7) cout << "Success!\n";
Ha egy vektor elemére hivatkozunk []-t kell használni és nem ()-t.
Az if -ben lévő igazságoperátort is át kell írni.

7. feladat
if (cond) cout << "Success!\n"; else cout << "Fail!\n";
if (true) cout << "Success!\n"; else cout << "Fail!\n"; 
A cond nincs deklarálva, ezért csak akkor kapjukhatjuk meg a kívánt kiíratást,
ha a ha mindig igaz 
 
8. feladat
bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
bool c = false; if (!c) cout << "Success!\n"; else cout << "Fail!\n";
Mivel a c hamis, mindig Fail lesz az output, 
vagy az elejénél kell átírnunk az értékét, vagy a ha-n belül kell negálnunk c-t.

9. feladat  
string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
string s = "ape"; bool c = "apc"<s; if (c) cout << "Success!\n"; 
A második sorban a bool el van írva.Továbbá, vagy a "fool"-t át kell írni egy olyan sztringre
aminek a számértéke kisebb, mint az "ape"-nek, vagy a relációs jelet kell megfordítanunk. 

10. feladat
string s = "ape"; if (s=="fool") cout << "Success!\n";
string s = "ape"; if (s=="ape") cout << "Success!\n";
Úgy kell átírnunk a kódot, hogy a tartalma megegyezzen a ha-n belüli sztringgel.

11. feladat
string s = "ape"; if (s=="fool") cout < "Success!\n";
string s = "ape"; if (s=="ape") cout << "Success!\n";  
A standard outputnál a cout után 2 << kell, továbbá az if-et úgy kell átírni, hogy igaz legyen.  

12. feladat
string s = "ape"; if (s+"fool") cout < "Success!\n";
string s = "ape"; if (s=="ape") cout << "Success!\n";
"+" átírása "=="-ra

13. feladat
vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";
vector<char> v(5); for (int i=0; i<v.size(); ++i) ; cout << "Success!\n";
A ciklusváltozót kell a vektor hosszával összehasonlítani, különben végtelen ciklus lesz..

14. feladat
vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
Nincs benne hiba.

15. feladat
string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];
Csak úgy tudjuk kiírni a teljes szrtinget, ha "i<s.size()".

16. feladat
if (true) then cout << "Success!\n"; else cout << "Fail!\n";
if (true) cout << "Success!\n"; else cout << "Fail!\n";  
Szintaxis hiba, a "then" megzavarja a fordítóprogramot, ki kell törölni. 

17. feladat
int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
int x = 2000; int c = x; if (c==2000) cout << "Success!\n";  Ha a c egy karakter változó, nem fogja tudni eltárolni a 2000-et, ami egy egész szám, 
tehát c-nek egész számnak kell lennie

18. feladat
string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];  Működik az alapkód is, de 2-szer feleslegesen fut le, akkor tökéletes, ha pont annyiszor fut le,
amennyi karaktere van a string-nek.

19. feladat
vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
vector<int> v(5); for (int i=0; i<v.size(); ++i) ; cout << "Success!\n";
Meg kell adni, hogy a vektor milyen tipusú értékeket fog tárolni, az i<=size()-t át kell írni i<size()-ra.

20. feladat
int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
int i=0; int j = 9; while (i<=(j+1)) ++i; if (j<i) cout << "Success!\n";
A while ciklust át kell írni, úgy, hogy az i értéke növekedjen.

21. feladat
int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
double x = 2; double d = 5/(x-1); if (d==2*x+1) cout << "Success!\n"; 
Ahhoz, hogy a d helyesen tárolja el a kifejezés értékét, meg kell változtatnunk a változó
típusát egy olyan típusra ami a valós számokat is képes kezelni. Pl.: double

22. feladat
string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
string s = "Success!\n"; for (int i=0; i<=s.size(); ++i) cout << s[i]; 
Helytelen szintaxis a kód elején, valamint a for cikluson elegendő s hosszaszor végigmenni. 

23. feladat
int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n"
int i=0,j=9; while (i<10) ++i; if (j<i) cout << "Success!\n";
Először deklarálnunk kell a j változó, majd a ciklusban növelnünk kell i-t.

24. feladat
double x = 4; double d = 5/(x–2); if (d=2*(x/2)+0.5) cout << "Success!\n";
double x = 4; double d=5/(x-2); if (d==(2*(x/4)+0.5)) cout << "Success!\n";
Az ha-n belül = helyett ==-t kell használnunk. És fontos a zárójeleket is helyesen rakjuk ki.

25. feladat
cin << "Success!\n"; | cout << "Success!\n"; 
cin helyett cout-ot kell használnunk.
*/