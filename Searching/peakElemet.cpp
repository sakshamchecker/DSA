#include <iostream>
using namespace std;
int getPeak(int a[],int n){ //Naive
	if(a[0]>a[1])	return a[0];
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]&&a[i]>a[i-1])	return a[i];
	}
	return -1;
}
int getPeak2(int a[],int n,int low,int high){
	int mid=(low+high)/2;
	if(low>high)	return -1;
	if(getPeak2(a,n,mid+1,high)!=-1)	return getPeak2(a,n,mid+1,high);
	if(getPeak2(a,n,low,mid-1)!=-1)		return getPeak2(a,n,low,mid-1);
	return -1;
}
int getPeak3(int a[],int n){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if((mid==0||a[mid-1]<=a[mid])&&(mid==n-1 || a[mid+1]<=a[mid]))
			return mid;
		if(mid>0 && a[mid-1]>=a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int a[]={1,1,1,1,1};
	cout<<getPeak2(a,5,0,4);
	return 0;
}