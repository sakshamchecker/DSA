#include <iostream>
#include <vector>
using namespace std;
void printSnake(vector<vector<int>> &a){
	int j=0,k;
	for(int i=0;i<a.size();i++){
		if(j==0)
			for(j;j<a[i].size();j++){
				cout<<a[i][j]<<' ';
			}
		else
			{for(k=j-1;k>=0;k--){
				//cout<<k<<' ';
				cout<<a[i][k]<<' ';
			}
			j=k+1;
		}

		//cout<<j<<endl;
	}
}
int main(int argc, char const *argv[])
{
	vector<vector<int>> a;
	for(int i=0;i<3;i++){
		vector<int> v;
		for(int j=0;j<3;j++){
			v.push_back(i+j);
		}
		a.push_back(v);
	}
	printSnake(a);
	return 0;
}