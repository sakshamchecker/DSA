#include <iostream>
using namespace std;

bool allo(string s1,string s2){
	if(s1.length()!=s2.length())	return 0;
	int count[256]={};
	for(auto x:s1)	count[x]++;
	for(auto y:s2)	count[y]--;
	for(auto x:count)	if(count[x]!=0)	return 0;
	return 1;
}
bool patt(string s1,string s2){
	int len=s2.length();
	for(int i=0;i<s1.length()-len+1;i++){
		if(allo(s1.substr(i,len),s2))	return 1;
	}
	return 0;
}
bool pattt(string s1,string s2){
	int count2[256]={},count1[256]={};
	for(auto x:s2)	count2[x]++;
	for(auto y:s1.substr(1,s2.length()))	count1[y]++;
	if 	
}
int main(int argc, char const *argv[])
{
	cout<<patt("Saksham","maa");
	return 0;
}