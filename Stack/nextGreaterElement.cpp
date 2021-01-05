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


vector<int> getGreater1(int a[],int n){ //Index
    vector<int> b(n);
    stack<int> s;
    b[n-1]=0;
    s.push(n);
    for(int i=n-2;i>=0;i--){
        while(s.empty()==0 && a[i]>a[s.top()-1]){
            s.pop();
        }
        b[i]=s.empty()?0:s.top();
        s.push(i+1);
    }
    return b;
}



int main(int argc, char const *argv[])
{
	int a[]={5,4,3,4,5};
	vector<int> b;
	b=getGreater1(a,5);
	for(int i=0;i<5;i++)	cout<<b[i]<<' ';
	return 0;
}