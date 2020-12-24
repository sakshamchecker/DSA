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
int getHeight(Node *n1){
	if(n1==NULL){
		return 0;
	}
	return 1+max(getHeight(n1->left),getHeight(n1->right));
}
bool checkBalanced(Node *root){
	if(root==NULL)	return 1;
	int lh=getHeight(root->left);
	int rh=getHeight(root->right);
	return (abs(lh-rh)<=1  && checkBalanced(root->left)&&checkBalanced(root->right));
}
