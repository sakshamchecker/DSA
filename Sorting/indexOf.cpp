#include <iostream>
using namespace std;
int getIndex0(int a[],int n,int x){
	for(int i=0;i<n;i++){
		if(x>a[i])	return -1;
		if(x==a[i])	return i;
	}
	return -1;
}
int getIndex(int a[],int low,int high,int x){ //recc
	if(low>high)	return -1;
	int mid=(low+high)/2;
	if(x>a[mid])	return getIndex(a,mid+1,high,x);
	else if(x<a[mid])	return getIndex(a,low,mid-1,x);
	else{
		if(mid==0|| a[mid-1]!=a[mid])
			return mid;
		return getIndex(a,low,mid-1,x);
	}
	return -1;
}
int getIndex1(int a[],int n, int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]>x)
			high=mid-1;
		else if(a[mid]<x)
			low=mid+1;
		else{
			if(mid==0||a[mid-1]!=a[mid])
				return mid;
			else
				high=mid-1;
		}
	}
	return -1;
}
int getIndexLast(int a[],int low,int high,int n,int x){
	int mid=(low+high)/2;
	if(x>a[mid])	return getIndexLast(a,mid+1,high,n,x);
	else if(x<a[mid])	return getIndexLast(a,low,mid-1,n,x);
	else{
		if(mid==n-1 || a[mid+1]!=a[mid])	return mid;
		return getIndexLast(a,mid+1,high,n,x);
	}
	return -1;
}
int getIndexLast1(int a[],int n , int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]>x)
			high=mid-1;
		else if(a[mid]<x)
			low=mid+1;
		else{
			if(mid==n-1||a[mid-1]!=a[mid])
				return mid;
			else
				low=mid+1;
		}
	}
	return -1;
}
int TotalOcc(int a[],int n,int x){
	int first = getIndex1(a,n,x);
	if(first=-1)	return 0;
	return getIndexLast1(a,n,x)-first+ 1;
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8};
	cout<<getIndex(a,0,8,7);
	return 0;
}