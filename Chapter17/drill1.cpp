#include "../std_lib_facilities.h"


// 4. Write a function print_array10(ostream& os, int* a)that prints
//out the values of a (assumed to have ten elements) to os.

void print_array10(ostream& os, int* a) {
	for(int i = 0; i < 10; i++)
		os << "nums2[" << i << "] = " << a[i] << endl;
}


// 7. Write a function print_array(ostream& os, int* a, int n) that
//prints out the values of a (assumed to have n elements) to os.

void print_array(ostream& os, int* a, int n) {
	for(int i = 0; i < n; i++)
		os << a[i] << endl;
}

// 10. Do 5, 6, and 8 using a vector instead of an array and a
//print_vector() instead of print_array().
void print_vector(ostream& os, vector<int> a) {
	for(int i = 0; i < a.size(); i++)
		os << a[i] << endl;
}

int main()
{
	// 1. Allocate an array of ten int s on the free store using new.

	int* nums = new int[10];

	// 2. Print the values of the 10 ints to cout.

	for (int i = 0; i < 10; ++i)
		cout << "nums[" << i << "] = " << nums[i] << endl;

	// 3. Deallocate the array (using delete[] ).
	//delete for one object, delete[] for an array of objects

	delete[] nums;

	// 5. Allocate an array of ten int s on the free store;
	//initialize it with the values 100, 101, 102, etc.;
	//and print out its values. 

	int* nums2 = new int[10];
	for (int i = 0; i < 10; ++i)
		nums2[i] = i + 100;

	print_array10(cout, nums2);
	delete[] nums2;


	// 6. Allocate an array of 11 int s on the free store; initialize
	//it with the values 100, 101, 102, etc.; and print out its values.
	
	int* nums3 = new int[11];
	for (int i = 0; i < 11; ++i)
		nums3[i] = i + 100;

	cout << "Values of num3" << endl;
	print_array(cout, nums3, 11);
	delete[] nums3;

	// 8. Allocate an array of 20 ints on the free store; initialize it
	//with the values 100, 101, 102, etc.; and print out its values.
 	
 	int* nums4 = new int[20];
	for (int i = 0; i < 20; ++i)
		nums4[i] = i + 100;

	cout << "Values of num4" << endl;
	print_array(cout, nums4, 20);
	delete[] nums4;

	// 10. Do 5, 6, and 8 using a vector instead of an array and a
	//print_vector() instead of print_array().

	vector<int> nums2_vector;
	for (int i = 0; i < 10; ++i)
		nums2_vector.push_back(100+i);

	cout << "Values of nums2_vector" << endl;
	print_vector(cout, nums2_vector);

	vector<int> nums3_vector;
	for (int i = 0; i < 11; ++i)
		nums3_vector.push_back(100+i);

	cout << "Values of nums3_vector" << endl;
	print_vector(cout, nums3_vector);

	vector<int> nums4_vector;
	for (int i = 0; i < 20; ++i)
		nums4_vector.push_back(100+i);

	cout << "Values of nums4_vector" << endl;
	print_vector(cout, nums4_vector);


	return 0;
}