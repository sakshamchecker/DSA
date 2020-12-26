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
Node *getSucc(Node *curr){
	curr=curr->right;
	while(curr!=NULL && curr->left==NULL)	curr=curr->left;
	return curr;
}
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
Node *insert2(Node *root, int x){//Recc
	if(root==NULL)	return new Node(x);
	else if (x>root->data)	root->right=insert(root->right,x);
	else if(x<root->data)	root->left=insert(root->left,x);
	return root;
}
bool search1(Node *root,int x){ //recc
	if(root==NULL)	return 0;
	if(root->data==x)	return 1;
	if(x>root->data)	return search1(root->right,x);
	if(x<root->data)	return search1(root->left,x);
	return 0;
}
bool search2(Node *root,int x){ //trans
	if(root==NULL)	return 0;
	if(root->data==x)	return 1;
	Node *curr=root;
	while(curr!=NULL){
		if(curr->data==x)	return 1;
		else if(x>curr->data)	curr=curr->right;
		else curr=curr->left;	
	}
	return 0;
}
void trans1(Node *n1){//Depth Inorder
	if(n1->left !=NULL){
		trans1(n1->left);
	}
	cout<<n1->data<<endl;
	if(n1->right!=NULL){
		trans1(n1->right);
	}
}
Node *delete1(Node* root, int x){ //trans
	if(root->data==x)
		if(root->right==NULL && root->left==NULL){
			delete(root);
			return NULL;
		}
	Node *present,*curr=root;
	while(curr->data!=x && curr!=NULL){
		present=curr;
		if(x>curr->data) curr=curr->right;
		else if(x< curr->data)	curr=curr->left;
	}
	if(curr->right==NULL && curr->left==NULL){
		delete(curr);
		if(x>present->data)	present->right=NULL;
		else if(x<present->data)	present->left=NULL;
	}

	return root;
}
Node *delNode(Node *root, int x){
	if(root==NULL)	return root;
	if(root->data>x)	root->left=delNode(root->left,x);
	else if(root->data <x)	root->right=delNode(root->right,x);
	else{
		if(root->left==NULL){
			Node *temp=root->right;
			delete (root);
			return temp;
		}
		else if(root->right==NULL){
			Node *temp = root->left;
			delete(root);
			return temp;
		}
		else{
			Node *succ=getSucc(root);
			root->data=succ->data;
			root->right=delNode(root->right,root->data);
		}
	}
	return root;
}

int main(int argc, char const *argv[])
{
	Node* root=new Node(15);
	root=insert(root,10);
	root=insert(root,20);
	//cout<<search2(root,20);
	//cout<<root->right;
	//trans1(root);
	root=delNode(root,10);
	trans1(root);
	return 0;

}