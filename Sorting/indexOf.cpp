#include <iostream>
using namespace std;
int getIndex(int a[],int n,int x){
	for(int i=0;i<n;i++){
		if(x>a[i])	return -1;
		if(x==a[i])	return i;
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8};
	cout<<getIndex(a,8,4);
	return 0;
}