#include <iostream>
using namespace std;
void maxHeapify(int a[],int i,int n){
	int largest=i,left=2*i+1,right=2*i+2;
	if(left<n && a[left]>a[largest])	largest=left;
	if(right<n && a[right]>a[largest])	largest= right;
	if(largest!=i){
		swap(a[largest],a[i]);
		maxHeapify(a,n,largest);
	}
}


void buildHeap(int a[],int n){
	for(int i=(n-2)/2;i>=0;i--)
		maxHeapify(a,n,i);
}


void heapSort(int a[],int n){
	buildHeap(a,n);
	for(int i=n-1;i>=1;i--){
		swap(a[0],a[i]);
		maxHeapify(a,i,0);
	}
}



int main(int argc, char const *argv[])
{
	int a[]={5,3,2,1};
	heapSort(a,4);
	return 0;
}