#include <iostream>
using namespace std;
// struct r{
// 	int len;
// };
int main()
{
	int a[]={20,25};
	int* b;
	b=a;
	*b++;
	cout<<b<<endl<<a<<endl<<*b<<endl<<&a;
	// cout<<*b;
}
