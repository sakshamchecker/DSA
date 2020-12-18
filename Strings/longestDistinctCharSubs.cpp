#include <iostream>
using namespace std;
const int cha=256;
int getLongest(string s1){
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
int main(int argc, char const *argv[])
{
	string s1="ababca";
	cout<<getLongest(s1);
	return 0;
}
