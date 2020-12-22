#include <iostream>
#include <queue>
using namespace std;

queue<int> reverse(queue<int> a){
	queue<int> b;
	while(a.empty()==0){
		b.push(a.front());
		a.pop();
	}
	return b;
}
void reverse1(queue<int> a){
	if(a.empty())	return;
	int x=a.front();
	a.pop();
	reverse(a);
	a.push(x);
}
int main(int argc, char const *argv[])
{
	queue<int> q;
	q.push(10);
	q.push(20);
	reverse1(q);
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front();
	q.pop();

	return 0;
}