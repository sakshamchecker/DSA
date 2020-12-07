#include <iostream>
using namespace std;
int maxi(int a[],int size){ //Function for Maximum in a array
	int ma=a[0];
	for(int i=0,j=size-1;i<j;i++,--j){
		ma=max(max(a[i],a[j]),ma);
	}
	return ma;
}
int mini(int a[],int size){ //Function for Minimum in a array
	int ma=a[0];
	for(int i=0,j=size-1;i<=j;i++,--j){
		ma=min(min(a[i],a[j]),ma);
	}
	return ma;
}
int main(){
	int a[6]={1000001,22,3,4,11,99};
	cout<<maxi(a,6)<<endl;
	cout<<mini(a,6);
	return 0;
}