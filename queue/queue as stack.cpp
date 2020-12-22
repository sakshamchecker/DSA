#include <iostream>
#include <queue>
using namespace std;
class Stack{
	queue<int> q1,q2;
public:
	int top(){	return q1.front();}
	int size(){	return q1.size();}
	int pop(){
		while(q1.empty()==0){
			q2.push(q1.front());
			q1.pop();
		}
		int temp=q2.front();
		q2.pop();
		while(q2.empty()==0){
			q1.push(q2.front());
			q2.pop();
		}
		return temp;
	}
	void push(int x){
		while(q1.empty()==0){
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(x);
		while(q2.empty()==0){
			q1.push(q2.front());
			q2.pop();
		}
	}
};
int main(int argc, char const *argv[])
{
	Stack s;
	s.push(10);
	s.push(20);
	cout<<s.top()<<endl<<s.size();
	s.pop();
	cout<<endl<<s.top()<<endl<<s.size();
	return 0;
}