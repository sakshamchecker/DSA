#include <iostream>
#include <math.h>
using namespace std;
int binToDec(int a){
	int i=0,b=0;
	while(a!=0){
		b+=(a%10)*pow(2,i);
		a=a/10;
		i++;
	}
	return b;
}
int main(int argc, char const *argv[])
{
	cout<<binToDec(011);
	return 0;
}