#include <iostream>
#include <vector>
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
void serialize(Node* root, vector<int> &d){
	if(root)	d.push_back(root->data);
	else{	d.push_back(-1);	return;}
	serialize(root->left,d);
	serialize(root->right,d);
}
int in=0;
Node* deserialize(vector<int> d){
	if(in==d.size())	return NULL;
	int val=d[in];
	in++;
	if(val==-1)	return NULL;
	Node* root=new Node(val);
	root->left=deserialize(d);
	root->right=deserialize(d);
	return root;
}
int main(int argc, char const *argv[])
{
	vector<int> d;
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	serialize(n1,d);
	for(auto x:d)	cout<<x<<' ';
	return 0;
}