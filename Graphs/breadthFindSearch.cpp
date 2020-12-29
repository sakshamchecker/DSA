#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void BFS(vector<int> adj[],int v,int s){ //Known source, Connected links
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=0;
	queue<int>	q;
	visited[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cout<<u<<' ';
		for(int i:adj[v]){
			if(visited[i]==0){
				visited[i]=1;
				q.push(i);
			}
		}
	}
}


void BFS1(vector<int> adj[],int s, bool visited[]){
	queue<int > 	q;
	visited[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cout<<u<<' ';
		for(int v:adj[u]){
			if(!visited[v]){
				visited[v]=1;
				q.push(v);
			}
		}
	}
}
void BFSdin(vector<int> adj[],int v){  //Not connected seperated loops
	bool visited[v+1]={};
	for(int i=0;i<v;i++){
		if(!visited[i])
			BFS1(adj,i,visited);
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
	BFSdin(a,v);
	return 0;
}