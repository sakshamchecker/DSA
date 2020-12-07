#include <iostream>
#include <list>
using namespace std;
struct MyHash
{
	int BUCKET;
	list<int> *table;
	MyHash(int b){BUCKET=b;	table=new list<int>[BUCKET];}
	void insert(int key){
		int i=hash(key);
		table[i].push_back(key);
	}
	bool search(int key){
		int i=hash(key);
		for(auto x:table[i]){
			if(x==key)	return 1;
		}
		return 0;
	}
	void remove(int key){
		int i=hash(key);
		table[i].remove(key);
	}
	int hash(int key){return key%BUCKET;}
};
int main(){
	MyHash aa(5);
	aa.insert(23);
	aa.insert(21);
	aa.insert(43);
	cout<<aa.search(43);
	aa.remove(23);
	cout<<endl<<aa.search(23);
	return 0;
}