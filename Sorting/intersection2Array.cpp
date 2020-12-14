#include <iostream>
using namespace std;
void intersection(int a[],int b[],int la,int lb){
	int i=0,j=0;
	while(i<la && j<lb){
		if(a[i-1]==a[i])	continue;
		if(a[i]==b[j]){
			cout<<a[i]<<endl;
			i++;
			j++;
		}
		else if(a[i]>b[j])	j++;
		else	i++;
	}
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8,9},b[]={1,4,5,7,9};
	intersection(a,b,9,5);
	return 0;
}