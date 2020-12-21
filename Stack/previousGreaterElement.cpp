#include <iostream>
#include <stack>
using namespace std;
void getGreater(int a[],int n){
	stack<int> s;
	s.push(a[0]);
	cout<<-1<<' ';
	for(int i=1;i<n;i++){
		while(s.empty()!=1 && a[i]>=s.top())
			s.pop();
		int greater=(s.empty())?-1:s.top();
		cout<<greater<<' ';
		s.push(a[i]);
	}
}
int main(int argc, char const *argv[])
{
	int a[]={4,3,5,2,1};
	getGreater(a,5);
	return 0;
}