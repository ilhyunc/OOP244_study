#include <iostream> // cin and cout
using namespace std;

int main()
{
	int temp = 300;
	cout << "Address of variable temp: " << (unsigned)&temp << endl;// 주소번호 계속 바뀜
	int* p;
	p = &temp;
	cout << "Content at the address: " << *p << endl;
	*p = *p + 1; //  ASCII code 기준.
	cout << "Content at the address: " << *p << endl;

	cout << "Size of pointer p: " << sizeof(p) << endl;

	//char* k;
	//cout << "Size of k: " << sizeof(k) << endl;
	//cout << "Size of *k: " << sizeof(*k) << endl;

	char* k = (char *)p; //  char = 8byte, int = 4byte
	
	cout << "*k is: " << *k << endl;

}

