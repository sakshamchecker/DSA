#include <iostream>
using namespace std;
void print0(int **a,int m, int n){ 
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cout<<a[i][j];
}

int main(int argc, char const *argv[])
{
	int m=3,n=3;
	int **a;
	a=new int*[m];
	for (int i = 0; i < m; ++i)
	{
		a[i]=new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j]=10;
			//cout<<a[i][j];
		}
	}
	//cout<<a[2][2];
	print0(a,3,3);
	return 0;
}