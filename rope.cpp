#include <iostream>
using namespace std;
int ma(int a,int b, int c){
	int max=a;
	if(a>max)	max=a;
	if(b>max)	max=b;
	if(c>max)	max=c;
	return max;
}
int rope(int n,int a, int b, int c){
	if(n<0)	return -1;
	if(n=0)	return 0;
	int maxi=ma(rope(n-a,a,b,c),rope(n-b,a,b,c),rope(n-c,a,b,c));
	if(maxi==-1)	return -1;
	return maxi+1;
}

main(){
	cout<<rope(9,2,2,2);
	return 0;
}