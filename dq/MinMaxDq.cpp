#include <iostream>
#include <deque>
using namespace std;
class datas{
	deque<int> dq;
public:
	void insertMax(int x){
		dq.push_back(x);
	}
	void insertMin(int x){
		dq.push_front(x);
	}
	int getMax(){
		return	dq.back();
	}
	int getMin(){
		return dq.front();
	}
	void deleteMax(){
		dq.pop_back();
	}
	void deleteMin(){
		dq.pop_front();
	}
};
int main(int argc, char const *argv[])
{
	datas a;
	a.insertMax(50);
	a.insertMin(10);
	a.deleteMin();
	cout<<a.getMin();
	return 0;
}