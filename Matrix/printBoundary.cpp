#include <iostream>
#include <vector>

using namespace std;

void printBoundary(vector<vector<int>> &a){
	for (int i = 0; i <a[0].size(); ++i)
	{
		cout<<a[0][i]<<' ';
	}
	for(int i=1;i<a.size();i++){
		cout<<a[i][a[0].size()-1]<<' ';
	}
	for(int i=a[0].size()-2;i>=0;i--){
		cout<<a[a.size()-1][i]<<' ';
	}
	for(int i=a.size()-2;i>0;i--){
		cout<<a[i][0]<<' ';
	}
}
void print(vector<vector<int>> a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			cout<<a[i][j]<<endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	int c=0;
	vector<vector<int>> v;
	for(int i=0;i<4;i++){
		vector<int> a;
		for(int j=0;j<3;j++){
			a.push_back(c);
			c++;
		}
		v.push_back(a);
	}
	//print(v);
	printBoundary(v);
	return 0;
}