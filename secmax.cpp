#include <iostream>
// int max(int a[],int size){
// 	int max=0;
// 	for(int i=0;i<size;i++){
// 		if(a[i]>max){
// 			max=a[i];
// 		}
// 	}
// 	return max;
// }
int secmax(int a[],int size){
	int max=a[0],sec=-1;
	for(int i=0;i<size;i++)
		if(a[i]>max){
			sec=max;
			max=a[i];
		}
	return sec;
}
using namespace std;
int main(){
	int a[]={4,4};
	cout<<secmax(a,2);
	return 0;
}
