#include <iostream>
using namespace std;
vector<int> LPS(string s){ //O(n)
	vector<int> l;
	l.push_back(0);
	int len=0;
	int i=1;
	while(i<s.length()){
		if(s[i]==s[len]){
			len++;
			l.push_back(len);
			i++;
		}
		else{
			if(len==0){l.push_back(0);	i++;	}
			else
				len=l[len-1];
		}
	}
	return l;
}
void kmp(string pat,string txt){
	int n=txt.length();
	int m=pat.length();
	vector<int> v;
	v=LPS(pat);
	int i=0,j=0;
	while(i<n){
		if(pat[j]==text[i]){i++;	j++;}
		if(j==m){cout<<i-j;	j=v[i-1];}
		else if(i<n && pat[i]!=text[i]){
			if(j==0)	i++;
			else	j=v[j-i];
		}
	}
}
