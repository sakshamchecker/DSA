#include <iostream>
using namespace std;


bool isSafe(string str,int i,int l,int r){
	if(l!=0 && str[i-1]=='A' && str[i] == 'B')
		return 0;
	if(r==l+1 && str[i]=='A' && str[l]=='B')
		return 0;
	return 1;
}




void printSubs(string str,int l,int r){
	if(l==r){
		cout<<str<<' ';
		return;
	}
	for(int i=l;i<=r;i++){
		if(isSafe(str,i,l,r)){
			swap(str[l],str[i]);
			printSubs(str,l+1,r);
			swap(str[l],str[i]);
		}
	}
}


int main(int argc, char const *argv[])
{
	string s1="ABC";
	printSubs(s1,0,2);
	return 0;
}