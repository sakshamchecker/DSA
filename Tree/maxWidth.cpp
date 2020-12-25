#include <iostream>
#include <queue>
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
int getWidth(Node *root){
	if(root==NULL)	return 0;
	queue<Node *> q;
	q.push(root);
	int res=0;
	while(!q.empty()){
		int count = q.size();
		res=max(res,count);
		for(int i=0;i<count;i++){
			Node *curr=q.front();
			q.pop();
			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	cout<<getWidth(n1);
	return 0;
}