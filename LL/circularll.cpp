#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node(int d){
		data=d;
		next=NULL;
	}
};
void trans(Node *head){ //dowhile
	if(head==NULL)	return;
	Node *curr=head;
	do{
		cout<<curr->data<<endl;
		curr=curr->next;
	}while(curr!=head);
}
Node* insertStart(Node *head,int data){ //O(n) //while Loop
	Node *temp=new Node(data),*curr=head;
	if(head==NULL){	temp->next=temp; return temp;}
	while(curr->next !=head){
		curr=curr->next;
	}
	curr->next=temp;
	temp->next=head;
	return temp;
}
Node *insertStart2(Node *head,int data){
	Node *temp = new Node(data);
	temp->next=NULL;
	if(head==NULL)	return temp;
	temp->next=head->next;
	head->next=temp;
	swap(head->next->data,head->data);
	return head;
}
Node *insertEnd(Node *head,int data){ //O(n)
	Node *temp=new Node(data),*curr=head;
	temp->next=temp;
	if(head==NULL)	return temp;
	while(curr->next!=head){
		curr=curr->next;
	}
	curr->next=temp;
	temp->next=head;
	return head;
}
Node *insertEnd2(Node *head,int data){ //O(1)
	Node *temp=new Node(data);
	temp->next=NULL;
	if(head==NULL)	return temp;
	temp->next=head->next;
	head->next=temp;
	swap(head->next->data,head->data);
	return(temp);
}
Node *deleteHead(Node *head){
	if(head->next==head){delete(head); return NULL;}
	//swap(head->data,head->next->data);
	head->data=head->next->data;
	Node *temp=head->next;
	head->next=head->next->next;
	delete(temp);
	return head;
}
Node *deleteKth(Node *head,int k){
	Node *curr=head;
	if(k==0)	return head;
	if(k==1)	return deleteHead(head);
	for(int i=1;i<k-1 && curr->next!=head;i++,curr=curr->next);
	if(curr->next==head)	return head;
	Node *temp=curr->next;
	curr->next=curr->next->next;
	delete(temp);
	return head;
}
int main(){
	Node *head = new Node(10);
	head ->next = new Node(20);
	head -> next ->next = new Node(40);
	head ->next ->next ->next = head;
	//head=insertEnd2(head,60);
	//head=deleteHead(head);
	head=deleteKth(head,3);
	trans(head);
	return 0;
}