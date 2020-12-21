#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int getArea(int a[],int n){ //Naive
	int res=0;
	for(int i=0;i<n;i++){
		int curr=a[i];
		for(int j=i-1;j>=0;j--){
			if(a[j]>=a[i])	curr+=a[i];
			else break;
		}
		for(int j=i+1;j<n;j++){
			if(a[j]>=a[i])	curr+=a[i];
			else break;
		}
		res=max(res,curr);
	}
	return res;
}
vector<int> leftMinArray(int a[],int n){
	stack<int> s;
	vector<int>	b(n);
	s.push(0);
	b[0]=-1;
	for(int i=1;i<n;i++){
		while(s.empty()==0 && a[s.top()]>=a[i]){
			s.pop();
		}
		b[i]=s.empty() ? -1:s.top();
		s.push(i);
	}
	return b;
}
vector<int> rightMinArray(int a[],int n){
	stack<int> s;
	vector<int> b(n);
	s.push(n-1);
	b[n-1]=n;
	for(int i=n-2;i>=0;i--){
		while(s.empty()==0 && a[s.top()]>=a[i]){
			s.pop();
		}
		b[i]=s.empty()? n : s.top();
		s.push(i);
	}
	return b;
}
int getArea1(int a[],int n){
	int res=0;
	vector<int> ls=leftMinArray(a,n);
	vector<int> rs=rightMinArray(a,n);
	for(int i=0;i<n;i++){
		int curr=0;
		curr+=(i-ls[i]-1)*a[i];
		curr+=(rs[i]-i-1)*a[i];
		res=max(res,curr);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int a[]={55,44,33,44,60};
	cout<<getArea1(a,5);
	return 0;
}
