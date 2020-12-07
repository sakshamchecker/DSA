#include <iostream>
using namespace std;
void currldr(int a[],int n){
	int c=a[n-1];
	cout<<c<<' ';
	for(int i=n-1;i>=0;i--){
		if(a[i]>c){
			c=a[i];
			cout<<c<<' ';
		}
	}
}
int main(int argc, char const *argv[])
{
	int a[]={6,3,5,10,7,8,3};
	currldr(a,7);
	return 0;
}
