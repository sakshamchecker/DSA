#include <iostream>
using namespace std;
int linsearch(int a[],int len,int n){
	for(int i=0;i<len;i++){
		if(a[i]==n)	return i;
	}
	return -1;
}
int binSearch(int a[], int n){
	int high=n-1,low=0;
	while(low<=high){
		int mid=low+high/2;
		if(a[mid]==n)	return mid;
		else if(n>a[mid])	low=mid+1;
		else high=mid-1;
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int a[]={10,10};
	cout<<binSearch(a,10);
	return 0;
}