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
bool childSum(Node *root){
	if(root==NULL)	return 1;
	if(root->left==NULL && root->right==NULL)	return 1;
	int sum=0;
	if(root->left)	sum+=root->left->data;
	if(root->right)	sum+=root->right->data;
return (root->data==sum && childSum(root->left) && childSum(root->right));	
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	cout<<childSum(n1);
	return 0;
}