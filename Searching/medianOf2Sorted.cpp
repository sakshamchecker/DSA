#include <iostream>
using namespace std;
float medianOf2Array(int a[],int b[],int la, int lb){
	int i=0,j=0, x=0;
	float w=1;
	int flag;
	if((la+lb)%2==0)	flag=(la+lb)/2 - 1;
	else flag=(la+lb)/2 ;
	while(x<flag){
		if(a[i]>b[j])	j++;
		else i++;
		x++;
	}
	if((la+lb) %2 ==0){
		int t,t1;
		if(a[i]>b[j])	{t=b[j];	j++;}
		else if(a[i]<b[j])	{t=a[i];	i++;}
		if(a[i]>b[j])	{t1=b[j];	j++;}
		else if(a[i]<b[j])	{t1=a[i];	i++;}
		return ((t+t1)/w)/2;
	}
	else
		return min(a[i],b[j]);
}
int main(int argc, char const *argv[])
{
	int a[]={1,3,5,7},b[]={2,4,6,8};
	cout<<medianOf2Array(a,b,4,4);
	return 0;
}