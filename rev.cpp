#include <iostream>
using namespace std;
int rev(int a[],int size){
	for(int i=0,j=size-1;i<size/2;i++,j--){
		swap(a[i],a[j]);
	}
	for(int i=0;i<size;i++)
		cout<<a[i];
	return 0;
}
int main(){
	int a[]={1,2,3,4,5,6};
	rev(a,6);
	return 0;
}