#include<iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
	priority_queue <int >	pq; // Max Heap
	priority_queue <int, vector<int>, greater<int>> pq1 //minheap
	pq.push(10);
	pq.push(20);
	pq.push(5);
	cout<<pq.top();
	return 0;
}