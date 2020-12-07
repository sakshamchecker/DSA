#include<iostream>
#include <stack>
#include <climits>
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
void trans1(Node *n1){//Depth Inorder
	if(n1->left !=NULL){
		trans1(n1->left);
	}
	cout<<n1->data<<endl;
	if(n1->right!=NULL){
		trans1(n1->right);
	}
}
void trans2(Node *n1){//Depth Preorder
	cout<<n1->data<<endl;
	if(n1->left !=NULL){
		trans1(n1->left);
	}
	if(n1->right!=NULL){
		trans1(n1->right);
	}
}
void trans3(Node *n1){//Depth Postorder
	if(n1!=NULL){
		trans1(n1->left);
		trans1(n1->right);
		cout<<n1->data<<endl;
	}
}
void trans4(Node *n1){//iterative
	stack<Node *> st;
	Node *curr=n1;
	while(curr!=NULL || st.empty()==0){
		while(curr!=NULL){
			st.push(curr);
			curr=curr->left;
		}
		curr=st.top();	st.pop();
		cout<<curr->data<<endl;
		curr=curr->right;
	}
}
void trans5(Node *n1){//Iterative Space  Efficient
	if(n1==NULL)	return;
	stack<Node *> st;
	Node *curr=n1;
	while(curr!=NULL || st.empty()==0){
		while(curr != NULL){
			cout<<curr->data<<endl;
			if(curr->right!=NULL)
				st.push(curr->right);
			curr=curr->left;
		}
		if(st.empty()==0){curr=st.top();	st.pop();}
	}
}
int getSize(Node *n1){//recc
	if(n1!=NULL){
		return 1+getSize(n1->left) + getSize(n1->right);
	}
	return 0;
}
int getMax(Node *n1,int ma=0){
	if(n1!=NULL){
		return max(max(n1->data,getMax(n1->left)),max(n1->data,getMax(n1->right)));
	}
	return INT_MIN;
}
int getHeight(Node *n1){
	if(n1==NULL){
		return 0;
	}
	return 1+max(getHeight(n1->left),getHeight(n1->right));
}
int main(int argc, char const *argv[])
{
	Node *n1=new Node(10);
	n1->left=new Node(5);
	n1->right=new Node(15);
	n1->left->left=new Node(22);
	n1->left->right=new Node(25);
	n1->right->left=new Node(99);
	//n1->right->right=new Node(88);
	//trans1(n1);
	//trans2(n1);
	//trans3(n1);
	//trans4(n1);
	trans5(n1);
	//cout<<getSize(n1);
	//cout<<getMax(n1);
	//cout<<getHeight(n1);
	return 0;
}