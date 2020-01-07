#include <iostream>
using namespace std;


int main_demo() {

	int arr[3] = { 0,1,2 };
	int* ip = arr;
	int* ip2 = &arr[0];
	cout << (ip == ip2) << endl;
	string a = "helo";
	char* ch = &a[0];

	cout << *ch << *(ch + 1) << *(ch + 2) << *(ch + 3) << endl;

	int ar[] = { 0,1,2 };
	for (int i : ar) {
		i = 3;
	}
	cout << ar[0] << ar[1] << ar[2] << endl;

	return 0;

}
