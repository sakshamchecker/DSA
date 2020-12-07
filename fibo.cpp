#include <iostream>
using namespace std;
int fibo(int n){
	if(n<2){
		cout<< 1;
		return 0;
	}
	cout<< fibo(n-1)+fibo(n-2);
	return 0;
}
int main(int argc, char const *argv[])
{
	fibo(5);
	return 0;
}