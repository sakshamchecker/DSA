#include<iostream>
using namespace std;

// diff(int a[],int n){
// 	int sul=0,sur=0;
// 	for(int i=0,j=0;i<n;i++,j++)	suj+=1;
// 	for(int i=0,j=n-1,i<n;i++,j--)	sur+=1;	
// 	cout<<sur<<endl<<suj;
// 	return 0
// }
int main(int argc, char const *argv[])
{
	int n=3,a[3][3]={1,2,3,4,5,6,7,8,9};
	int suj=0,sur=0;
	for(int i=0,j=0;i<n;i++,j++)	suj+=a[i][j];
	for(int i=0,j=n-1;i<n;i++,j--)	sur+=a[i][j];	
	cout<<sur<<endl<<suj;
	return 0;
}