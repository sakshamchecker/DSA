#include <iostream>
using namespace std;
bool check(int a[],int b[]){
	for(int i=0;i<256;i++){
		if(a[i]!=b[i])	return 0;
	}
	return 1;
}
bool checkAnnogram(string s1,string s2){
	int cs[256]={};
	int cm[256]={};
	for(int i=0;i<s2.length();i++){
		cm[s1[i]]++;
		cs[s2[i]]++;
	}
	for(int i=s1.length();i<s2.length();i++){
		if(check(cs,cm))	return 1;
		cm[s2[i-s2.length()]]-=1;
		cm[s2[i]]+=1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	string s1="abcd",s2="ab";
	cout<<checkAnnogram(s1,s2);
	return 0;
}