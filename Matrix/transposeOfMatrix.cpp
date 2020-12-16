#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> &transpose(vector<vector<int>> &a){
	for(int i=0;i<a.size();i++)
		for(int j=i;j<a[i].size();j++){
			swap(a[i][j],a[j][i]);
		}
	return a;
}
void print(vector<vector<int>> a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
int main(int argc, char const *argv[])
{
	int c=0;
	vector<vector<int>> v;
	for(int i=0;i<3;i++){
		vector<int> a;
		for(int j=0;j<3;j++){
			a.push_back(c);
			c++;
		}
		v.push_back(a);
	}
	print(v);
	cout<<endl;
	v=transpose(v);
	print(v);
	return 0;
}