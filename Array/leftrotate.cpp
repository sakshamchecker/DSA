#include <iostream>
using namespace std;
void leftShift0(int a[],int size){ //naive
	//int count=0;
	for (int i = size-1; i>=0; i--)
	{
		if(a[i]==0)
		{
			for(int j=i;j<size-1;j++){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<size;i++){
		cout<<a[i];
	}
}
int leftSingleShift(int a[],int size){ //naive
	int temp=a[0];
	for(int i=0;i<size;i++){
		a[i]=a[i+1];
	}
	a[size-1]=temp;
	for(int i=0;i<size;i++)
		cout<<a[i];
	cout<<endl;
	return 0;
}
void leftShift(int a[],int size,int d){ //O(nd)
	while(d--)
	for(int i=0;i<size-1;i++){
		swap(a[i],a[i+1]);
	}
}
void leftShift2(int a[],int n,int d){//O(n),Extra Space
	int temp[d];
	for(int i=0;i<d;i++)	temp[i]=a[i];
	for(int i=d;i<n;i++)	a[i-d]=a[i];
	for(int i=0;i<d;i++)	a[n-d+i]=temp[i];
}
void reverse(int a[],int low,int high){
	while(low<=high){
		swap(a[low],a[high]);
		low++;
		high--;
	}
}
void leftShift3(int a[],int n,int d){ 
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
}

int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5};
	leftShift3(a,5,2);
	for(int i=0;i<5;i++)	cout<<a[i];
	return 0;
}