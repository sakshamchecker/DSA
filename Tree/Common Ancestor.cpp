#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int x){
		data=x;
		left=right= NULL;
	}
};
bool findPath(Node *root,vector<Node*> p,int n){
	if(root==NULL)	return 0;
	p.push_back(root);
	if(root->data==n)	return 1;
	if(findPath(root->left,p,n)||findPath(root->right,p,n))
		return 1;
	p.pop_back();
	return 0;
}
Node *lca(Node *root, int m, int n){
	vector<Node*> pathm,pathn;
	if(!findPath(root,pathm,m) || !findPath(root,pathn,n))
		return NULL;
	for(int i=0;i<pathm.size()-1 && i<pathn.size()-1;i++)
		if(pathm[i+1]!=pathn[i+1])
			return pathn[i];
	return NULL;
}
Node *lca2(Node *root , int m , int n){
	if(root==NULL)	return NULL;
	if(root->data==m||root->data==n)	return root;
	Node *lca1=lca(root->left,m,n);
	Node *lca2=lca(root->right,m,n);
	if(lca1 && lca2)	return root;
	if(lca1)	return lca1;
				return lca2;	
}
int main(int argc, char const *argv[])
{
	 Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	Node *temp=lca2(n1,99,22);
	//cout<<temp->left->data;
	return 0;
}