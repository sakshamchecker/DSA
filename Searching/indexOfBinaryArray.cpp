#include<iostream>
using namespace std;
int count1s(bool a[],int n){
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==0)
			low=mid+1;
		else{
			if(mid==0 || a[mid-1]!=a[mid])
				return (n-mid);
			else high=mid-1;
		}
	}
	return 0;
}
int main(){
	bool a[]={0,0,0,0,0,0,0,1,1,1,1,1,1,1};
	cout<<count1s(a,13);
	return 0;
}
