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
void printKth(Node *root, int k){
	if(root==NULL)	return;
	if(k==0)	cout<<root->data<<' ';
	else{
		printKth(root->left,k-1);
		printKth(root->right,k-1);
	}
}
int main(){
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	printKth(n1,1);
}