#include <iostream>
using namespace std;
#include <vector>

const int cha=256;
int getLongest(string s1){ //O(n2)
	int ma=0;
	for(int j=0;j<s1.length();j++){
		int temp=0;
		int count[256]={};
		for(int i=j;i<s1.length();i++){
			if(count[s1[i]]==0){
				count[s1[i]]++;
				temp++;
			}
			else	break;
		}
		ma=max(ma,temp);
	}
	return ma;
}
int getLongest1(string s1){ //O(n)
	int n=s1.length();
	int res=0;
	vector<int> prev(256,-1);
	int i=0;
	for (int j = 0; j < n; ++j){
		i=max(i,prev[s1[j]]+1);
		int maxEnd=j-i+1;
		res=max(res,maxEnd);
		prev[s1[i]]==j;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	string s1="ababca";
	cout<<getLongest(s1);
	return 0;
}
