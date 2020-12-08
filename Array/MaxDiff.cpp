#include <iostream>
using namespace std;
int MaxDiff(int a[], int size){
	int max=a[0],min=a[0];
	for(int i=0;i<size;i++){
		if(max<a[i])	max=a[i];
		if(a[i]<min)	min=a[i];
	}
	return max-min;
}
int stockProfit(int a[],int size){
	return MaxDiff(a,size);

}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5};
	cout<<MaxDiff(a,5);
	return 0;
}