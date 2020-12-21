#include <iostream>
#include <stack>
using namespace std;
void getSpan(int a[],int n){
	for(int i=0;i<n;i++){
		int span=1;
		for(int j=i-1;j>=0;j--){
			if(a[i]<=a[j])
				span++;
			else
				break;
		}
		cout<<span;
	}
}
void getSpan2(int a[],int n){
	stack<int>	s;
	s.push(0);
	cout<<1<<" ";
	for(int i=1;i<n;i++){
		while(s.empty()==0 && a[s.top()]<=a[i])
			s.pop();
		int span=(s.empty())? i+1: i-s.top();
		cout<<span<<" ";
		s.push(i);
	}
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5};
	getSpan2(a,5);
	return 0;
}

