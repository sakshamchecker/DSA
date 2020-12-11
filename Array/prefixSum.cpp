#include<iostream>
using namespace std;
int getSum1(int a[],int b,int c){ //O(n)
	int su=0;
	for(int i=b;i<=c;i++)	su+=a[i];
	return su;
}
int getSum2(int a[],int n,int b,int c){
	int prefix_sum[n];
	prefix_sum[0]=a[0];
	for(int i=0;i<n;i++){
		prefix_sum[i]=a[i]+prefix_sum[i-1];
	}
	return prefix_sum[c]-prefix_sum[b-1];
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7};
	cout<<getSum1(a,2,4)<<endl<<getSum2(a,7,2,4);
	return 0;
}