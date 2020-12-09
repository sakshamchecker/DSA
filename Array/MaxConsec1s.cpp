#include <iostream>
using namespace std;
int ones(int a[],int size){
	int temp=0,count=0;
	for(int i=0;i<size;i++){
		if(a[i]==1)	temp++;
		else if(a[i]==0){
			count=max(count,temp);
			temp=0;
		}
	}
	if(a[size-1]==1){
		count=temp;
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int a[]={1,1,1,0,0,0,0,1,1,1,1,1,1};
	cout<<ones(a,13);
	return 0;
}
