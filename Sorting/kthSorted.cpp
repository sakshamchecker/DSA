#include <iostream>
using namespace std;
int partition(int a[],int l,int h){ //lomuto(Partition about last number in array)
	int pivot=a[h];
	int i = l-1;
	for(int j=l;j<=h-1;j++){
		if(a[j]<pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[h]);
	return(i+1);
}
int getKth(int a[],int n,int k){
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		int p=partition(a,l,r);
		if(p==k-1)
			return p;
		else if(p>k-1)
			r=mid-1;
		else
			l=mid+1;

	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int a[]={1,4,6,7,2,3,6};
	cout<<getKth(a,7,3);
	return 0;
}