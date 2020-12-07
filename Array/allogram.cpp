#include <iostream>
#include <climits>
using namespace std;
bool allo(string s1,string s2){
	if(s1.length()!=s2.length())	return 0;
	int count[256]={};
	for(auto x:s1)	count[x]++;
	for(auto y:s2)	count[y]--;
	for(auto x:count)	if(count[x]!=0)	return 0;
	return 1;
}
int occ(string s1){
	int count[256]={};
	for(auto x:s1)	count[x]++;
	for(int i=0;i<s1.length();i++)	if(count[s1[i]]>1)	return i;
	return -1;
}
int firstrep(string s1){
	int res=INT_MAX;
	int fi[256];
	for(int i=0;i<256;i++)	fi[i]=-1;
	for(int l=0;i<s1.length(),i++){
		
	}
}
int occ1(string s1){
	int count[256]={};
	for(auto x:s1)	count[x]++;
	for(int i=0;i<s1.length();i++)	if(count[s1[i]]==1)	return i;
	return -1;
}
int main(int argc, char const *argv[])
{
	cout<<occ1("xyzshbsam");
	return 0;
}
