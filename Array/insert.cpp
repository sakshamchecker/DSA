#include <iostream>
using namespace std;
int insert(int a[],int len,int pos, int x)
{
	if(pos==len)
	{
		return -1;
	}
	int idx=pos-1;
	for(int i=len-1;i>=idx;i--)
	{
		a[i+1]=a[i];
	}
	a[idx]=x;
	cout<<a[1];
	return 0;
}
int main()
{
	int a[5]={1,2,3};
	insert(a,5,2,66);
	return 0;
}