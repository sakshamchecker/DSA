#include <iostream>
#include <map>
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
void vSumR(Node *root,int hd, map<int,int> mb){
	if(root==NULL)	return;
	vSumR(root->left,hd-1,mb);
	mb[hd]+=root->data;
	vSumR(root->right,hd+1,mb);
}
void vSum(Node *root){
	map<int,int> mb;
	vSumR(root,0,mb);
	for(auto sum:mb)
		cout<<sum.second<<" ";
}
int main(int argc, char const *argv[])
{
	Node* root=new Node(15);
	root=insert(root,10);
	root=insert(root,20);
	vSum(root);	
	return 0;
}