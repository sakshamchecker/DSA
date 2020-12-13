#include <iostream>
using namespace std;
bool search2sum(int a[],int n,int x,int left=0,int right=0){
	if(right==0)	right=n-1;
	while(left<right){
		if(a[left]+a[right]==x)	break;
		else{
			if(a[right]>x)	right--;
			if(a[left]+a[right] < x)	left++;
			if(a[left]+a[right] > x)	right--;
		}
	}
	if(a[left]+a[right]==x){
		return 1;
	}
	else
		return 0;
}
bool search3sum(int a[],int n,int x){
	for(int i=0;i<n;i++){
		if(search2sum(a,n,x-a[i],i+1,n-1))	return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8,9};
	cout<<search3sum(a,9,20);
	return 0;
}
