#include <iostream>
#include <stack>
using namespace std;
class Stack{
	stack<int> main;
	stack<int> aux;
public:
	void push_(int x){
		main.push(x);
		if(aux.empty() || x<aux.top())	aux.push(x);
	}
	void pop_(){
		if(main.top()==aux.top()){
			main.pop();
			aux.pop();
		}
		else
			main.pop();
	}
	int getMin(){
		return aux.top();
	}
};
int main(int argc, char const *argv[])
{
	Stack s;
	s.push_(10);
	cout<<s.getMin()<<endl;
	s.push_(5);
	cout<<s.getMin();
	s.pop_();
	cout<<endl<<s.getMin();
	return 0;
}
