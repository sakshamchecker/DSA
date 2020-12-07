#include <iostream>
using namespace std;
int checkSubSum(int a[],int size,int sum){
	if(n==0)	return (sum==0)?1:0;
	return checkSubSum(a,size-1,sum)+checkSubSum(a,size-1,sum-a[size-1]);
}
