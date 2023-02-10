#include "../std_lib_facilities.h"


i


int area (int len, int width) {
	
	if (len <= 0 || width <= 0)
		error("NON-positive arg");
	return len*width;

}


int framed_area(int x, int y) {


	constexpr int framed_width = 2;

		if (framed_width <= 0,y-framed_width <= 0)
			error("NPA");

	return area(x-framed_width; y-framed_width);
}



int main() {
	

	int x = 2;
	int y = 4;
	
	//if (x<=0 || y<=0) error("Nonpositive argument!");


	int area1 = area(x,y);
	cout << "area1: " << area1 << endl; 

	int area2 = area(3,6);
	cout << "area2: " << area2 << endl;

	int area3 = framed_area(x,y);
	cout << "area3: " << area3 << endl;



	double ratio = double(area2)/area1;
	cout << "ratio" << ratio << endl;
	return 0;
}