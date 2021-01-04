#include <iostream>
#include <stack>
#include <vector>

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


vector<int> getGreater1(int a[],int n){
	stack<int> s;
	vector<int> b(n);
	s.push(1);
	b[0]=0;
	for(int i=1;i<n;i++){
		while(s.empty()!=1 && a[i]>=a[s.top()-1])
			s.pop();
		int greater=(s.empty())?0:s.top();
		b[i]=greater;
		s.push(i+1);
	}
	return b;
}



int main(int argc, char const *argv[])
{
	int a[]={5,4,3,4,5};
	//getGreater(a,5);
	vector<int> b=getGreater1(a,5);
	for(int i=0;i<5;i++)	cout<<b[i]<<' ';
	return 0;
}