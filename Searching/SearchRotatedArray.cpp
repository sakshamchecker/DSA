#include <iostream>
using namespace std;
int search(int a[],int n,int x,int low,int high){
	int mid=(low+high)/2;
	if(a[mid]==x)	return mid;
	if(a[mid]>x){
		if(x>a[low])	return search(a,n,x,low,mid-1);
		else if(x<a[low])	return search(a,n,x,mid+1,high);
	}
	else if(a[mid]<x){
		if(x>a[high])	return search(a,n,x,low,mid-1);
		else if(x<a[high])	return search(a,n,x,mid+1,high);
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int a[]={10,20,30,40,50,60,4,8};
	cout<<search(a,8,80,0,7);
	return 0;
}