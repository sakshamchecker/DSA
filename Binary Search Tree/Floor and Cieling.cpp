#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};
Node* Floor(Node* root,int x){
	Node *res=NULL;
	while(root){
		if(root->data==x)	return root;
		else if(root->data>x)	return root->left;
		else{	res=root;root=root->right;}
	}
	return res;
}
Node* ciel(Node* root, int x){
	Node *res=NULL;
	while(root){
		if(root->data==x)	return root;
		if(root->data<x)	root=root->right;
		else{
			res=root;
			root=root->left;
		}
	}
	return res;
}
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
int main(int argc, char const *argv[])
{
	Node* root=new Node(15);
	root=insert(root,10);
	root=insert(root,20);
	cout<<ciel(root,14)->data;
	return 0;
}