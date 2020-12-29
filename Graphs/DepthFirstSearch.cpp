#include <iostream>
#include <queue>
#include <vector>
using namespace std;


void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void dfsRec(vector<int> a[],int s,bool visited[]){
	visited[s]=1;
	cout<<s<<' ';
	for(int u:a[s]){
		if(!visited[u])	dfsRec(a,u,visited);
	}
}



void dfs(vector<int> a[],int v,int s){    //Connected
	bool visited[v]={};
	dfsRec(a,s,visited);
}


void dfs1(vector<int> adj[],int v){ //disconnected
	bool visited[v]={};
	for(int i=0;i<v;i++){
		if(!visited[i])	dfsRec(adj,i,visited);
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
	dfs1(a,v);
	return 0;
}