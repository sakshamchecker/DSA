#include <iostream>
using namespace std;
class Queue{
	int size;
	struct Node
	{
		int data;
		Node *next;
		Node(int x)	{
			data=x;
			next=NULL;
		}
	};
	Node* insertBegin(Node *he,int n){
		Node *ne=new Node(n);
		ne->next = he;
		return ne;
	}
	Node* delFirst(Node *head){
		if(head==NULL)	 return NULL;
		Node *curr=head->next;
		delete(head);
		return curr;
	}
	void trans(Node *he){//loop
		Node *head=he;
		while(head!= NULL){
			cout<<head->data<<endl;
			head=head->next;
		}
	}
	Node *head;
public:
	Queue(){
		size=0;
	}
	void enque(int x){
		if(size==0){	head=new Node(x);	size++;	return;}
		head=insertBegin(head,x);
	}
	void dequeu(){
		if(size==0){	cout<<"Underflow";	return; }
		head=delFirst(head);
	}
	bool isEmpty(){
		if(size==0) 	return 1;
		return 0;
	}
	int getSize(){
		return size;
	}
	void transv(){
		trans(head);
	}
};
int main(int argc, char const *argv[])
{
	Queue a=Queue();
	cout<<a.isEmpty();
	a.enque(50);
	a.enque(39);
	//a.dequeu();
	a.transv();
	return 0;
}