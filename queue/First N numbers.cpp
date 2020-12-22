#include <iostream>
#include <queue>
using namespace std;
void print(int n){
	queue<string> q;
	q.push("5");
	q.push("6");
	for(int i=0;i<n;i++){
		string curr=q.front();
		cout<<curr<<' ';
		q.pop();
		q.push(curr+'5');
		q.push(curr+'6');
	}
}
int main(int argc, char const *argv[])
{
	print(10);
	return 0;
}
