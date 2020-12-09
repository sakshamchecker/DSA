#include <iostream>
using namespace std;
int getWater(int a[],int n){//Naive
	int res=0,lmax,rmax;
	for(int i=1;i<n-1;i++){
		lmax=a[i];
		rmax=a[i];
		for(int j=i;j>0;j--)
			lmax=max(lmax,a[j]);
		for(int j=i;j<n;j++)
			rmax=max(rmax,a[j]);
		res=res+min(lmax,rmax)-a[i];
	}
	return res;
}
int getWater2(int a[],int n){ //O(N)
	int res=0,lmax[n],rmax[n];
	lmax[0]=a[0];
	rmax[n-1]=a[n-1];
	for(int i=1,j=n-1;i<n,j>=0;i++,j--){
		lmax[i]=max(a[i],lmax[i-1]);
		rmax[j]=max(a[j],rmax[j+1]);
	}
	for(int i=1;i<n-1;i++)
		res=res+min(lmax[i],rmax[i])-a[i];
	return res;
}
int main(int argc, char const *argv[])
{
	int a[]={5,0,5,3,2,3};
	cout<<getWater2(a,6);
	return 0;
}