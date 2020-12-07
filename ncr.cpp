#include <iostream>
using namespace std;
double ncr(double n, double r){
	if((n<0 && r<0)||(r>n))	return -1;
	if(r==0) return 1;
	//if(r==1) return n;
	return (n-r+1)*ncr(n,r-1)/r;
}
int main(){
	cout<<ncr(10,1);
	return 0;
}