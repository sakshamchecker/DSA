#include <iostream>
using namespace std;
int search(int a[],int n,int x){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==x)	return mid;
		if(a[low]<a[mid]){
			if(x>=a[low]&&x<a[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		else{
			if(x>a[mid]&& x<=a[high])
				low=mid+1;
			else
				high=mid-1;
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int a[]={10,20,30,40,50,60,4,8};
	cout<<search(a,8,4);
	return 0;
}