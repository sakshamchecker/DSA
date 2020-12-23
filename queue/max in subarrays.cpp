#include <iostream>
#include <deque>
using namespace std;
void maxInSub(int arr[],int n,int k){
	deque<int> dq;
	for(int i=0;i<k;i++){
		while(dq.empty()==0 && arr[i]>dq.back())
			dq.pop_back();
		dq.push_back(i);
	}
	for(int i=k;i<n;i++){
		cout<<arr[dq.front()]<<' ';
		while(!dq.empty() && dq.front()<=i-k)
			dq.pop_front();
		while(!dq.empty() && arr[i]>dq.back())
			dq.pop_back();
		dq.push_back(i);
	}
	cout<<arr[dq.front()];
}
int main(int argc, char const *argv[])
{
	int a[]={3,2,4,1,5,4,3,2,6,77};
	maxInSub(a,10,3);
	return 0;
}