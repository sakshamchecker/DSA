#include <iostream>
using namespace std;
int sub(string str, string curr="",int index=0){
	if(index==str.length()){	cout<<curr;	return 0;	}
	sub(str,curr,index+1);
	sub(str,curr+' '+str[index],index+1);
	return 0;
}
int main(int argc, char const *argv[])
{
	sub("abc");
	return 0;
}