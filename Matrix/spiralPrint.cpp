#include <iostream>
#include <vector>

using namespace std;

void printSpiral(vector<vector<int>> &a){
	int top=0,left=0,bottom=a.size()-1,right=a[0].size()-1;
	while(top<=bottom && left<=right){
		for(int i=left;i<=right;i++)
			cout<<a[top][i]<<" ";
		top++;
		for(int i=top;i<=bottom;i++)
			cout<<a[i][right]<<' ';
		right--;
		if(top<=bottom){
			for(int i=right;i>=left;i--)
				cout<<a[bottom][i]<<' ';
			bottom--;
		}
		if(left<=right){
			for(int i=bottom;i>=top;i--)
				cout<<a[i][right]<<' ';
			left++;
		}
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
	printSpiral(v);
	return 0;
}