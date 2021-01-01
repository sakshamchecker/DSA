#include <iostream>
#include <queue>
using namespace std;
void sortK(int a[],int n,int k){
	priority_queue<int , vector<int>,greater<int>> pq;
	for(int i=0;i<=k;i++)
		pq.push(a[i]);
	int index=0;
	for(int i=k+1;i<n;i++){
		a[index++]=pq.top();
		pq.pop();
		pq.push(a[i]);
	}
	while(!pq.empty()){
		a[index++]=pq.top();
		pq.pop();
	}
}
int main(int argc, char const *argv[])
{
	int a[]={3,2,1};
	sortK(a,3,3);
	for(auto x:a)	cout<<x;
	return 0;
}