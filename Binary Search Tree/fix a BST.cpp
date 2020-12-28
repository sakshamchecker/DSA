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
Node *pre=NULL,*first=NULL,*sec=NULL;
void getSwap(Node *root){
	if(!root)	return;
	getSwap(root->left);
	if(pre!=NULL && ((root->data) < (pre->data))){
		if(first==NULL)
			first=pre;
		sec=root;
	}
	pre=root;
	getSwap(root->right);
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	getSwap(n1);
	swap(first,sec);
	return 0;
}