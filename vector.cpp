#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v){
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<'\n';
	}
}
int main(){
	vector<int> vec1;
	int a;
	for (int i = 0; i < 4; ++i)
	{
		cout<<"Enter";
		cin>>a;
		vec1.push_back(a);
	}
	display(vec1);
	return 0;
}


