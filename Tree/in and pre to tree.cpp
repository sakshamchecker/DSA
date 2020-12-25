#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* left,*right;
	Node(int x){
		left=right=NULL;
		data=x;
	}
};
int preIndex=0;
Node *getTree(int in[],int pre[],int is, int ie){
	if(is>ie)	return NULL;
	Node *root=new Node(pre[preIndex++]);
	int inIndex;
	for(int i=is;i<=ie;i++){
		if(in[i]==root->data){
			inIndex=i;
			break;
		}
	}
	root->left=getTree(in, pre, is, inIndex-1);
	root->right=getTree(in,pre,inIndex+1,ie);
	return root;
}
int main(int argc, char const *argv[])
{
	Node *temp;
	int a[]={20,10,30,40,50},b[]={10,20,30,40,50};
	getTree(a,b,0,4);
	return 0;
}