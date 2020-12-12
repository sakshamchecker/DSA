#include <iostream>
using namespace std;
int sqrt(int a){ //Naive
	for(int i=0;i<a/2;i++){
		if(i*i <=a)
			if((i+1)*(i+1) >a)
				return i;
	}
	return 0;
}
int sqrt1(int x){ //Binary Type
	int low=1,high=x,ans=-1;
	while(low<=high){
		int mid=(low+high)/2;
		int msq=mid*mid;
		if(msq==x)	return mid;
		else if(msq>x){
			high=mid-1;
		}
		else{
			low=mid+1;
			ans=mid;
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	cout<<sqrt1(100);
	return 0;
}