#include <iostream>
#include <vector>
using namespace std;


void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void print(vector<int> adj[],int v){
	for(int i=0;i<v;i++){
		for(int x:adj[i])
			cout<<x<<' ';
		cout<<'\n';
	}
}
int main(int argc, char const *argv[])
{
	int v=4;
	vector<int> a[v];
	addEdge(a,0,1);
	addEdge(a,0,2);
	addEdge(a,1,2);
	addEdge(a,1,3);
	print(a,v);
	return 0;
}
