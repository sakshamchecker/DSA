#include <iostream>
using namespace std;
int kill(int n, int k){
	if(n==1)	return 0;
	return (kill(n-1,k)+k)%n;
}
int main(int argc, char const *argv[])
{
	cout<<kill(5,3);
	return 0;
}