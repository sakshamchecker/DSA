#include <iostream>
#include <list>

using namespace std;

int main(){

	list<int> list1;
	list<int> list2(7);
	list1.push_back(5);

	list<int> :: iterator iter;
	iter=list1.begin();

	cout<<*iter;
}
main()