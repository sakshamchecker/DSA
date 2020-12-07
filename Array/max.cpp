#include <iostream>
using namespace std;

int max(int a[],int size){
	int max=0;
	for(int i=0;i<size;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}

int main(){
	int a[]={11,9889};
	int x=max(a,2);
	cout<<x;
	return 0;
}