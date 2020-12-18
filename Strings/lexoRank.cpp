#include <iostream>
using namespace std;
const int cha=256;
int fact(int n){
	int f=1;
	while(n>1){
		f*=n;
		n--;
	}
	return f;
}
int getRank(string s1){
	int count[cha]={};
	int res=1;
	int n=s1.length();
	int mul=fact(n);
	for(int i=0;i<n;i++){
		count[s1[i]]++;
	}
	for(int i=0;i<cha;i++){
		count[i]+=count[i-1];
	}
	for(int i=0;i<n-1;i++){
		mul/=(n-i);
		res+=count[s1[i]-1]*mul;
		for(int j=s1[i];j<cha;j++){
			count[j]--;
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	string s1="ab";
	cout<<getRank(s1);
	return 0;
}