#include <iostream>
#include <stack>
using namespace std;
void print(stack<char> s1){
	while(s1.empty()==0){
		cout<<s1.top()<<endl ;
		s1.pop();
	}
}
// void mer(stack<char> s1,stack<char> s2){
// 	string a[s1.size() + s2.size()];
// 	int i=0;
// 	while(s1.empty()==0){
// 		a[i]=s1.top();
// 		s1.pop();
// 		i++;
// 	}
// 	while(s2.empty()==0){
// 		a[i]=s2.top();
// 		s2.pop();
// 		i++;
// 	}
// 	for(int i=0;a[i]!='\0';i++)	cout<<a[i]<<endl;
// }
bool balancedPara(string s){
	stack<int> s1;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='['|| s[i]=='{'|| s[i]=='('){
			s1.push(s[i]);
		}
		else if(s[i]==']'){
			if(s1.empty())	return 0;
			else if(s1.top()=='[')
				s1.pop();
			else	return 0;
		}
		else if(s[i]=='}'){
			if(s1.empty())	return 0;
			else if(s1.top()=='{')
				s1.pop();
			else	return 0;
		}
		else if(s[i]==')'){
			if(s1.empty())	return 0;
			else if(s1.top()=='(')
				s1.pop();
			else	return 0;
		
		}
	}
	return s1.empty();
}
bool opMatch(char x){
	return(x=='*'|| x=='-'|| x=='-' || x=='+' || x=='/');
}
void postToPre(string a){
	stack<char> s1,s2;
	for(int i=0;a[i]!='\0';i++){
		if(opMatch(a[i])==false)
			s1.push(a[i]);
		else
			s2.push(a[i]);
	}
	print(s1);
	cout<<endl;
	print(s2);
}

int main(int argc, char const *argv[])
{
	string s1="x+y*z";
	//cout<<balancedPara(s1);
	// stack<int> s1;
	// s1.push(50);
	// s1.push(20);
	// print(s1);
	// s1.pop(50);
	//cout<<endl<<endl<<s1.top();
	postToPre(s1);
	return 0;
}