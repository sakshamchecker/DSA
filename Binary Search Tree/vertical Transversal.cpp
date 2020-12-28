#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int x){
		data=x;
		left=right= NULL;
	}
};


Node* insert(Node *root,int x){
	Node* curr=root,*temp=new Node(x),*present;
	if(root==NULL)	return temp;
	while(curr!=NULL){
		present = curr;
		if(x<curr->data)	curr=curr->left;
		else if(x>curr->data)	curr=curr->right;
		else if (x==curr->data)	return root;
	}
	if(x>present->data)	present->right=temp;
	else if(x<present->data)	present->left= temp;
	return root;
}

void vPrintR(Node *root,int hd, map<int,vector<int>> mb){
	if(root==NULL)	return;
	vPrintR(root->left,hd-1,mb);
	mb[hd].push_back(root->data);
	vPrintR(root->right,hd+1,mb);
}
void vPrint(Node *root){
	map<int,vector<int>> mb;
	vPrintR(root,0,mb);
	for(auto arr:mb)
		for(auto x:arr.second)
			cout<<x<<' ';
}

void vTrans(Node* root){
	map<int, vector<int>> mp;
	queue<pair<Node*,int>> q;
	q.push({root,0});
	while(!q.empty()){
		auto p=q.front();
		Node *curr=p.first;
		int hd=p.second;
		mp[hd].push_back(curr->data);
		q.pop();
		if(curr->left)	q.push({curr->left,hd-1});
		if(curr->right)	q.push({curr->right,hd-1});

	}

	for(auto p:mp){
		vector<int> v= p.second;
		for(int x:v)
			cout<<x<<' ';
		cout<<'\n';
	}
}
int main(int argc, char const *argv[])
{
	Node* root=new Node(15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,5);
	vPrint(root);
	vTrans(root);
	return 0;
}