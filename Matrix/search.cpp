#include <iostream>
#include <vector>
using namespace std;
const int r=3;
const int c=3;
void serch(vector<vector<int>> &a,int x){
	int m=a.size(),n=a[0].size(),i=0,j=0;
	while(i<m){
		//cout<<i<<','<<j<<' ';
		if(a[0][i]==x){	cout<<i<<','<<j<<' ';	return;}
		if(a[0][i]>x)	break;
		i++;
	}
	i-=2;
	while(j<n){
		//cout<<i<<','<<j<<' ';
		if(a[j][i]==x){	cout<<i<<','<<j;	return;}
		if(a[j][i]>x)	return;
		j++;
	}
}
void search1(int a[r][c],int x){
	int i=0,j=c-1;
	while(i<r && j>=0){
		if(a[i][j]==x){	
			cout<<i<<','<<j;
			return;
		}
		else if(a[i][j]>x)
			j--;
		else
			i++;
	}
	cout<<"Not Found";
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
	for(int i=0;i<4;i++){
		vector<int> a;
		for(int j=0;j<3;j++){
			a.push_back(c);
			c++;
		}
		v.push_back(a);
	}
	//print(v);
	cout<<endl;
	serch(v,1);
	return 0;
}