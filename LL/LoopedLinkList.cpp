#include <iostream>
#include <unordered_set>
using namespace std;
struct Node{
	int data;
	Node *next;
	bool visited;
	Node(int x){
		data=x;
		next=NULL;
		visited=0;
	}
};
bool detect(Node *head){
	if(head==NULL)	return 0;
	Node *curr=head;
	while(curr->next!=NULL){
		if(curr->next->visited)	return 1;
		curr->visited=1;
		curr=curr->next;
	}
	return 0;
}
bool detect1(Node *head){ //Low Space
	Node* temp = new Node(0);
    while (head != NULL) {
 
        // This condition is for the case
        // when there is no loop
        if (head->next == NULL) {
            return false;
        }
 
        // Check if next is already
        // pointing to temp
        if (head->next == temp) {
            return true;
        }
 
        // Store the pointer to the next node
        // in order to get to it in the next step
        Node* nex = head->next;
 
        // Make next point to temp
        head->next = temp;
 
        // Get to the next node in the list
        head = nex;
	}
	return 0;
}
bool detect3(Node *head){
	unordered_set<Node *> s;
	for(Node *curr=head;curr!=NULL;curr=curr->next){
		if(s.find(curr)!=s.end())
			return 1;
		s.insert(curr);
	}
	return 0;
}
bool detect4(Node *head){ //Floyd
	Node *slow_p = head, *fast_p = head;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}
Node* removeLoop(Node *head){ //extraAux
	if(head==NULL)	return 0;
	Node *curr=head;
	while(curr->next!=NULL){
		if(curr->next->visited)	curr->next=NULL;
		curr->visited=1;
		curr=curr->next;
	}
	return head;
}
void removeLoop2(Node *head){ //Floyd used
	Node *slow=head,*fast=head;
	while(slow && fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			break;
		}
	if(slow!=fast)	return;
	slow=head;
	while(slow->next!=fast->next){
		slow=slow->next;
		fast=fast->next;
	}
	fast->next=NULL;
	}
}
Node* insertEnd(Node *head,int n){
	Node *temp=new Node(n);
	if(head==NULL)	return temp;
	Node *curr=head;
	while(curr->next !=NULL)
		curr=curr->next;
	curr->next=temp;
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
	Node *head=new Node(20);
	Node *curr=head;
	head=insertEnd(head,30);
	head=insertEnd(head,10);
	head->next->next->next=curr->next;
	cout<<detect4(head);
	return 0;
}