#include "../std_lib_facilities.h"


int main()
{
	
	//1. feladat
	int num = 7;
 	int* p1 = &num;

 	//2. feladat
 	cout << "p1: " << p1 << "\t&p1: " << &p1 << endl;
 	
 	//3. feladat
 	int* p2 = new int[7] {1, 2, 4, 8, 16, 32, 64};

	//4. feladat
 	for (int i = 0; i < 7; ++i)
 		cout <<"elements of p2\t" << &p2[i]
 		<< "\t corresponding value\t" << &p2[i] << endl;

 	//5. feladat
 	int* p3 = p2;

 	//6. feladat
 	p1 = p2;

 	//7. feladat
 	p3 = p2;

 	//8. feladat
 	cout << endl;
 	for (int i = 0; i < 7; ++i)
 		cout <<"elements of p1\t" << &p1[i]
 		<< "\t corresponding value\t" << &p1[i] << endl;

 	cout << endl;
 	for (int i = 0; i < 7; ++i)
 		cout <<"elements of p2\t" << &p2[i]
 		<< "\t corresponding value\t" << &p2[i] << endl;

 	//9. feladat
 	delete[] p2;
 	
 	//10. feladat
 	p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

 	//11. feladat
 	p2 = new int[10];

 	//12. feladat
 	for (int i = 0; i<10; ++i)
        	p2[i] = p1[i];

     delete[] p1;
     delete[] p2;

    //13. feladat
     vector<int> p1_vector = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
     vector<int> p2_vector;

     for (int i = 0; i<p1_vector.size(); ++i)
        	p2_vector.push_back(p1_vector[i]);
	return 0;
}