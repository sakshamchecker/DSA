#include <iostream>
using namespace std;
int maxcon(int a[],int n, int k){
	int maxs=0,curr=0;
	for(int i=0;i<n;i++){
		if(i<k){
			maxs+=a[i];
			curr+=a[i];
		}
		else{
			curr=curr+a[i]-a[i-k];
			maxs=max(maxs,curr);}
	}
	return maxs;
}
int main(int argc, char const *argv[])
{
	int a[]={1,6,3,4,1,1,9,1};
	cout<<maxcon(a,8,2);
	return 0;
}
