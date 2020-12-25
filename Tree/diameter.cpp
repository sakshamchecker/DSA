#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* left,*right;
	Node(int x){
		left=right=NULL;
		data=x;
	}
};
int rightHeight(Node *root){
	if(root==NULL)	return 0;
	Node *curr=root;
	int rh=1;
	while(curr->right){
		curr=curr->right;
		rh++;
	}
	return rh;
}
int leftHeight(Node *root){
	if(root==NULL)	return 0;
	Node *curr=root;
	int lh=1;
	while(curr->left){
		curr=curr->left;
		lh++;
	}
	return lh;
}
int getDiameter(Node *root){
	if(root==NULL)	return 0;
	return max(max(getDiameter(root->left),getDiameter(root->right)),1+rightHeight(root->right)+leftHeight(root->left));
}
int res=0;
int height(Node *root){
	if(root==NULL) return 0;
	int lh=height(root->left);
	int rh=height(root->right);
	res=max(res,1+lh+rh);
	return 1+max(lh,rh);
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->right=new Node(5);
	n1->right->right=new Node(1);
	//cout<<getDiameter(n1);
	cout<<height(n1);
	cout<<res;
	return 0;
}