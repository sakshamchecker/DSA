#include <iostream>
#include <unordered_set>
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
Node* insert(Node *root,int x){
	Node* curr=root,*temp=new Node(x),*present;
	if(root==NULL)	return temp;
	while(curr!=NULL){
		present = curr;
		if(x<curr->data)	curr=curr->left;
		else if(x>curr->data)	curr=curr->right;
		else if (x==curr->data)	return root;
	}
	if(x>present->data)	present->right=temp;
	else if(x<present->data)	present->left= temp;
	return root;
}
bool isPairSum(Node *root,int sum, unordered_set<int> &s){
	if(root==NULL)	return 0;
	if(isPairSum(root->left,sum,s))	return 1;
	if(s.find(sum-root->data)!=s.end())	return 1;
	else			s.insert(root->data);
	return isPairSum(root->right,sum,s);
}
int main(int argc, char const *argv[])
{
	Node* root=new Node(15);
	root=insert(root,10);
	root=insert(root,20);
	unordered_set<int>	s;
	cout<<isPairSum(root,10,s);
	return 0;
}