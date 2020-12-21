#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> getGreater(int a[],int n){
	vector<int> b(n);
	stack<int> s;
	b[n-1]=-1;
	s.push(a[n-1]);
	for(int i=n-2;i>=0;i--){
		while(s.empty()==0 && a[i]>=s.top()){
			s.pop();
		}
		b[i]=s.empty()?-1:s.top();
		s.push(a[i]);
	}
	return b;
}
int main(int argc, char const *argv[])
{
	int a[]={11,55,33,22,67};
	vector<int> b;
	b=getGreater(a,5);
	for(int i=0;i<5;i++)	cout<<b[i]<<' ';
	return 0;
}