#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node *prev;
	Node(int x){
		data=x;
		next=prev=NULL;
	}
};
Node * insertBeg(Node *head,int data){
	Node *curr=head, *temp=new Node(data);
	temp->next=curr;
	if(head!=NULL)	curr->prev=temp;
	return temp;
}
Node *insertEnd(Node *head,int data){
	Node *curr=head,*temp=new Node(data);
	if(head==NULL)	return temp;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	temp->prev=curr;
	return head;
}
void trans(Node *head){
	Node *curr = head;
	if(head==NULL)	return;
	while(curr!=NULL){
		cout<<curr->data<<endl;
		curr=curr->next;
	}
}

int main()
{
	Node *head=new Node(10);
	head=insertBeg(head,20);
	head=insertBeg(head,40);
	head=insertEnd(head,50);
	trans(head);
	//cout<<head->data<<endl<<head->next->data;
	return 0;
}