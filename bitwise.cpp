#include <iostream>
using namespace std;
void set(int a, int b){
	if(a&(1<<(b-1)))
		cout<<"yes";
	else
		cout<<"NO";
}
int main(int argc, char const *argv[])
{
	set(5,3);
	return 0;
}