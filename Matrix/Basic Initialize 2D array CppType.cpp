#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> a[],int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<a[i].size();j++){
			cout<<a[i][j]<<endl;
		}
	}
}

int main(){
	int m=3,n=3;
	vector<int> a[m];
	vector<vector<int>>	b;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i].push_back(10);
		}
	}
	for(int i=0;i<m;i++){
		vector<int> v;
		for(int j=0;j<n;j++){
			v.push_back(10);
		}
		b.push_back(v);
	}
	print(a,m);
	return 0;
}