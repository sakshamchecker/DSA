#include <iostream>
#include <math.h>
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
int countNode(Node* root){
	if(root==NULL)	return 0;
	return 1+countNode(root->left)+countNode(root->right);
}
int countNode1(Node *root){
	int lh=0,rh=0;
	Node *curr=root;
	while(curr){
		lh++;
		curr=curr->left;
	}
	curr=root;
	while(curr){
		rh++;
		curr=curr->right;	
	}
	if(rh==lh)
		return pow(2,lh)-1;
	return 1+countNode1(root->left)+countNode1(root->right);
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	cout<<countNode1(n1);
	return 0;
}