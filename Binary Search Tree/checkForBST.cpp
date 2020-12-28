#include <iostream>
#include <limits>
#include <climits>
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
bool check(Node* root, int min=INT_MIN,int max=INT_MAX){ //Using Limits
	if(root==NULL)	return 1;
	return ((root->data)>=min && (root->data)<=max) && check(root->left,min,root->data) && check(root->right,root->data,max);	
}
int mini=INT_MIN;
bool check1(Node* root){
	if(root==NULL)	return 1;
	if(check1(root->left)==0)	return 0;
	if(root->data <= mini)	return 0;
	mini=root->data;
	return check1(root->right);
}
int main(int argc, char const *argv[])
{
	Node* root=new Node(15);
	root=insert(root,10);
	root=insert(root,20);
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	cout<<check1(n1);
	return 0;
}