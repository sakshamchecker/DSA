#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node{
	int data;
	Node* left,*right;
	Node(int x){
		left=right=NULL;
		data=x;
	}
};
void printSpiral(Node *root){
	if(root==NULL)	return;
	queue<Node *>	q;
	stack<int> s;
	bool reverse=0;
	q.push(root);
	while(!q.empty()){
		int count=q.size();
		for(int i=0;i<count;i++){
			Node *curr=q.front();
			q.pop();
			if(reverse)
				s.push(curr->data);
			else
				cout<<curr->data<<' ';
			if(curr->left)	q.push(curr->left);
			if(curr->right)	q.push(curr->right);
		}
		if(reverse){
			while(!s.empty()){
				cout<<s.top()<<' ';
				s.pop();
			}
			reverse=!reverse;
		}
	}
}
void printSpiral2(Node *root){
	if(root==NULL)	return;
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			Node *curr=s1.top();
			s1.pop();
			cout<<curr->data<<' ';
			if(curr->right)	s2.push(curr->right);
			if(curr->left)	s2.push(curr->left);
		}
		while(!s2.empty()){
			Node *curr=s2.top();
			s2.pop();
			cout<<curr->data<<' ';
			if(curr->left)	s1.push(curr->left);
			if(curr->right)	s1.push(curr->right);
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
	printSpiral(n1);
	cout<<endl;
	printSpiral2(n1);
	return 0;
}
