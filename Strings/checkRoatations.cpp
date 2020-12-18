#include <iostream>
#include <string>

using namespace std;
bool check(string &s1,string &s2){
	if(s1.length()!=s2.length())	return 0;
	return ((s1+s1).find(s2)!=string::npos);
}
int main(int argc, char const *argv[])
{
	string s1="ABCDE",s2="CDEAB";
	cout<<check(s1,s2);
	return 0;
}
