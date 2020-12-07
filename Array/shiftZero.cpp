#include <iostream>
using namespace std;
void shiftZero(int a[],int size){
	int pos0=0;
	for(int i=0;i<size;i++){
		if(a[i]!=0){
			swap(a[i],a[pos0]);
			pos0++;
		}
	}
}
int main(int argc, char const *argv[])
{
	int a[]={0,1,0,0,0,1,1,0,1};
	shiftZero(a,9);
	for(int i=0;i<9;i++)	cout<<a[i];
	return 0;
}
