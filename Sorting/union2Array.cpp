#include <iostream>
using namespace std;
void getUnion(int a[],int b[],int la,int lb){
	int i=0,j=0;
	while(i<la && j<lb){
		if(a[i-1]==a[i]){	i++;	continue;}
		if(b[j-1]==b[j]){	j++;	continue;}
		if(a[i]==b[j]){
			cout<<a[i];
			i++;
			j++;
		}
		else if(a[i]<b[j]){
			cout<<a[i];
			i++;
		}
		else{
			cout<<b[j];
			j++;
		}
	}
	for(i;i<la;i++)	cout<<a[i];
	for(j;j<lb;j++)	cout<<b[j];
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,2,4,5,6,7},b[]={2,4,6,8,9};
	getUnion(a,b,7,5);
	return 0;
}