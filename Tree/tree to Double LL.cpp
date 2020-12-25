#include <iostream>
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
struct Node *prevv=NULL;
Node *treetoDLL(Node *root){
	if(root==NULL)	return root;
	Node *head=treetoDLL(root->left);
	if(prevv==NULL)	head=NULL;
	else{
		root->left=prevv;
		prevv->right=root;
	}
	prevv=root;
	treetoDLL(root->right);
	return head;
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	treetoDLL(n1);
	return 0;
}