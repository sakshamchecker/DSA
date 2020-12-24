#include <iostream>
#include <queue>
int maxlev=0;
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
void leftView(Node *root , int level){
	if(root==NULL)	return;
	if(maxlev<level){
		cout<<root->data<<" ";
		maxlev=level;
	}
	leftView(root->left,level+1);
	leftView(root->left,level+1);
}
void leftView2(Node *root){
	if(root==NULL)	return;
	queue<Node*> q;
	q.push(root);
	while(q.empty()==0){
		int count=q.size();
		for(int i=0;i<count;i++){
			Node *curr=q.front();
			q.pop();
			if(i==0)
				cout<<curr->data<<' ';
			if(curr->left==NULL)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
	}
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	leftView2(n1);
	return 0;
}