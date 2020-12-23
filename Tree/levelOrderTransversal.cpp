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
void printLevel(Node *root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		Node *curr=q.front();
		q.pop();
		if(curr==NULL){
			cout<<endl;
			q.push(NULL);
			continue;
		}
		cout<<curr->data<<' ';
		if(curr->left!=NULL)	q.push(curr->left);
		if(curr->right!=NULL)	q.push(curr->right);
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
	printLevel(n1);
	return 0;
}