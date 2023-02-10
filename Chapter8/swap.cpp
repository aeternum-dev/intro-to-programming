#include "../std_lib_facilities.h"

void swap_v(int a,int b) {
	int temp;
	temp = a, 
	a=b; 
	b=temp;
	return;
	}

void swap_r(int& a, int& b) {
	int temp;
	temp = a, 
	a=b; 
	b=temp;
	return;
	}


//Ez a függvény nem fordítódik le, mivel
//konstansokat próbál megváltoztatni.
/*void swap_cr(const int& a, const int& b) {
	int temp;
	temp = a, 
	a=b; 
	b=temp; 
	return;
	}*/

int main() {
	int x = 7;
	int y = 9;
	swap_v(x,y);
	cout <<"x: " << x <<" y: "<< y << endl;
	//x: 7 y: 9
	//a és b felcserélődött a függvényen belül 


	swap_r(x,y);
	cout <<"x: " << x <<" y: "<< y << endl;
	//x: 9 y: 7

	swap_v(7, 9);
	cout <<"x: " << x <<" y: "<< y << endl;
	//a és b felcserélődött a függvényen belül 

	//Nem fordítódik le, mivel a 7-es
	//számot próbálja egyenlővé tenni 9-cel.
	/*swap_r(7, 9);
	cout <<"x: " << x <<" y: "<< y << endl;*/

	const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);
	cout <<"cx: " << cx <<" cy: "<< cy << endl;
	//cx: 7 cy: 9

	//nem fordítódik le mivel konstansot próbál megváltoztatni
	/*swap_r(cx,cy);
	cout <<"cx: " << cx <<" cy: "<< cy << endl;*/
	
	swap_v(7.7,9.9);
	//A függvényen belül a számok egész részével dolgozott
	//és felcserélte őket.

	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);
	cout <<"dx: " << dx <<" dy: "<< dy << endl;
	//dx: 7.7 dy: 9.9
	//A függvényen belül a számok egész részével dolgozott
	//és felcserélte őket. 


	//nem fordítódik le, mivel a double változóba próbál int-et írni.
	/*swap_r(dx,dy);
	cout <<"dx: " << dx <<" dy: "<< dy << endl; */

	return 0;
}