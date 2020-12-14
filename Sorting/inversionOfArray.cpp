#include <iostream>
using namespace std;
int getInversion(int a[],int n){ //Inversion is when i<j and a[i]>a[j]
	int count;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j]<a[i])	count++;
		}
	}
	return count;
}
int mergeAndGet(int a[],int l, int m, int r){
	int n1=m-l+1,n2=r-m;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)	left[i]=a[l+i];
	for(int i=0;i<n2;i++)	right[i]=a[m+i+1];
	int res=0,i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(left[i]<=right[i]){a[k]=left[i];	i++;}
		else{
			a[k]=right[j];	j++;	res+=n1-i;}
		}
	while(i<n1){	a[k]=left[i];	i++;	k++;}
	while(j<n2){	a[k]=right[j];	j++;	k++;}
	return res;
}

int getInversion1(int a[],int l,int r){ //Efficient
	int res=0;
	if(l<r){
		int m=l+(r-l)/2;
		res+=getInversion1(a,l,m-1);
		res+=getInversion1(a,m+1,r);
		res+=mergeAndGet(a,l,m,r);
	}
	return res;

}
int main(int argc, char const *argv[])
{
	int a[]={9,8,7,6,5,4,3,2,1};
	cout<<getInversion(a,9);
	return 0;
}