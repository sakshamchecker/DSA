#include <iostream>
using namespace std;
strlen(string str,int len=0){
	if(str[len]=='\0')	return len;
	return strlen(str,len+1);
}
cons(string str,int i=0,int con=0){
	if(str[i]=='\0')	return con;
		
}
int main(int argc, char const *argv[])
{
	cout<<strlen("");
	return 0;
}