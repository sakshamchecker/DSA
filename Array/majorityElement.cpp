#include<iostream>
using namespace std;
int posMajEle(int a[],int n){ //Naive
	int count,temp=0,res=0;
	for(int i=0;i<n;i++){
		count=0;
		for(int j=i;j<n;j++){
			if(a[i]==a[j])	count++;
		}
		if(count>res){
			temp=i;
			res=max(res,count);
		}
	}
	if(res>n/2)	return res;
	return -1;
}
int posMajEle2(int a[],int n){
	int res=0,count=1;
	for(int i=1;i<n;i++){
		if(a[res]==a[i])
			count++;
		else
			count--;
		if(count==0){	res=i;	count=1;}
	}
	count=0;
	for(int i=0;i<n;i++){
		if(a[res]==a[i])
			count++;
	}
	if(count<n/2)	return -1;
	return res;
}
int main(int argc, char const *argv[])
{
	int a[]={1,3,2,4,5,2,2,2,5};
	cout<<posMajEle2(a,9);
	return 0;
}