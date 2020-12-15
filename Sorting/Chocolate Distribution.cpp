#include <iostream>
using namespace std;
int parti(int a[],int l,int h){ //lomuto(Partition about last number in array)
	int pivot=a[h];
	int i = l-1;
	for(int j=l;j<=h-1;j++){
		if(a[j]<pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	//cout<<i;
	swap(a[i+1],a[h]);
	return(i+1);
}
void qSort(int a[],int l, int h){
	begin:
	if(l<h){
		int p=parti(a,l,h);
		qSort(a,l,p);
		l=p+1;
		goto begin;
	}
}
void sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min])	min=j;
		}
		swap(a[i],a[min]);
	}
}
int distriChocolates(int a[],int n,int m){
	if(m>n){
		return -1;
	}
	sort(a,n);
	int res=a[n-1]-a[0];
	for(int i=1;i+m-1 < n; i++){
		res=min(res,a[i+m-1]-a[i]);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,9,4,11};
	cout<<distriChocolates(a,6,2);
	return 0;
}