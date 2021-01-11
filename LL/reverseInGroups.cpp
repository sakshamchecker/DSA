#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x){
		data=x;
	}
};
Node *reverseInGroups(Node *head,int k){ //recc
	Node *curr=head,*next=NULL,*prev=NULL;
	int count=0;
	while(curr!=NULL && count <k){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL){
		Node *rest_head=reverseInGroups(next,k);
		head->next=rest_head;
	}
	return prev;
}
Node *reverseK(Node *head,int k){
	Node *curr=head,*prevFirst=NULL;
	bool flag=1;
	while(curr->next!=NULL){
		Node *first=curr,*prev=NULL;
		int count=0;
		while(curr!=NULL && count <k){
			Node* next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			count++;
		}
		if(flag){head=prev;	flag=0;}
		else
			prevFirst->next=prev;
		prevFirst=first;
	}
	return head;
}
void listTrans(Node *he){//loop
	Node *head=he;
	while(head!= NULL){
		cout<<head->data<<endl;
		head=head->next;
	}
}
int main(int argc, char const *argv[])
{
	Node *a=new Node(10);
	a->next=new Node(20);
	a->next->next=new Node(30);
	a=reverseK(a,2);
	//listTrans(a);

	return 0;
}
