#include<iostream>
using namespace std;
// int maxSubSum(int a[],int n){ //SpaceExtra
// 	int temp[n];
// 	temp[0]=a[0];
// 	for(int i=1;i<n;i++){
// 		temp[i]=temp[i-1]+a[i];
// 	}
// 	int mi=a[0],ma=a[0],m;
// 	for(int i=1;i<n;i++){
// 		if(ma<a[i]){
// 			ma=max(a[i],ma);
// 			ma=i;
// 		}
// 		if(a[i]<mi || i<m)
// 			mi=min(a[i],mi);
// 	}
// 	if(mi>0)	return ma;
// 	return ma-mi;
// }
int maxSubSum2(int a[],int n){ //Space Efficient
	int res=a[0];
	int maxEnd=a[0];
	for(int i=1;i<n;i++){
		maxEnd=max(maxEnd+a[i],a[i]);
		res=max(res,maxEnd);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int a[]={33,2,4,11,-1,-33,4,3,44};
	cout<<endl<<maxSubSum2(a,9);
	return 0;
}