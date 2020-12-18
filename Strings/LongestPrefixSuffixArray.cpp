#include <iostream>
#include <vector>

using namespace std;
int longest(string s1,int x){
	int ma=0;
	int n=x;
	for(int i=0;i<n;i++){
		bool flag=1;
		for(int j=0;j<=i;j++){
			if(s1[j]!=s1[n-i+j]){	flag=0;	break;}
		}
		if(flag)	ma=max(ma,i+1);
	}
	return ma;
}
vector<int> LPS(string s1){	//O(n3)
	vector<int> v;
	for(int i=0;i<s1.length();i++){
		v.push_back(longest(s1,i));
	}
	return v;
}
vector<int> LPS1(string s){ //O(n)
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
int main(int argc, char const *argv[])
{
	string s1="abcabc";
	vector<int> v=LPS1(s1);
	for(auto x:v)	cout<<x<<",";
	/* code */
	return 0;
}