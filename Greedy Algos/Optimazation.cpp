#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void bubsort(int a[],int n){
	// bool swapped;
	for(int i=0;i<n-1;i++){
		// swapped=0;
		for(int j=0;j<n-1-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				// swapped=1;
			}
		}
		// if(swapped==1)	break;
	}
}


int minCoins(int a[],int n,int k){
	bubsort(a,5);
	int res=0;
	for(int i=0;i<n;i++){
		if(a[i]<=k){
			int c=(k/a[i]);
			res+=c;
			k-=c*a[i];
		}
		if(k==0)	break;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	int a[]={5,4,3,2,1};
	cout<<minCoins(a,5,3);
	return 0;
}