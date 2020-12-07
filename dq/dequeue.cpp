#include <iostream>
#include <deque>
using namespace std;
int main(int argc, char const *argv[])
{
	deque<int> d={1,2,3};
	auto it=d.begin();
	d.insert(it,222);
	d.push_front(50);
	d.erase(it+1);
	d.push_back(10);
	d.pop_front();
	for(auto x : d)	cout<<x<<' ';
	cout<<d.back();
	return 0;
}
