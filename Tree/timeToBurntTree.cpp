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
int res=0;
int burnTree(Node *root,int leaf,int &dist){
	if(root==NULL)	return 0;
	if(root->data==leaf){dist=1;return 1;}
	int ld=-1,rd=-1;
	int lh=burnTree(root->left,leaf,ld);
	int rh=burnTree(root->right,leaf,rd);
	if(ld!=-1){
		dist=ld+1;
		res=max(res,dist+rh);
	}
	else if(rd!=-1){
		dist=rd+1;
		res=max(res,lh+dist);
	}
	return max(lh,rh)+1;
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	int d=0;
	cout<<burnTree(n1,99,d);
	return 0;
}