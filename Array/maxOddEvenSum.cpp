#include <iostream>
using namespace std;
int getOddEven(int a[],int n){ //m1
	int temp=0,res=0;
	int x;
	for(int i=0;i<n;i++){
		if(temp==0)	x=a[i]%2;
		if(i%2==0){
			if(a[i]%2==x)	temp++;
			else{
				res=max(res,temp);
				temp=0;
			}
		}
		else {
			if(a[i]%2!=x)	temp++;
			else{
				res=max(res,temp);
				temp=0;
			}
		}
	}
	return res;
}
int getOddEven2(int a[],int n){ //m2
	int count=1,res=1;
	for(int i=1;i<n;i++){
		if((a[i]%2 == 0 && a[i-1]%2!=0)||(a[i]%2!=0 && a[i-1]%2==0)){
			count++;
			res=max(res,count);
		}
		else
			count=1;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int a[]={2,3,5,5,7,8,9,10,6,6};
	cout<<getOddEven2(a,10);
	return 0;
}