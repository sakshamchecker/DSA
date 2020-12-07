#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}
};
void listTrans(Node *he){//loop
	Node *head=he;
	while(head!= NULL){
		cout<<head->data<<endl;
		head=head->next;
	}
}
void listTrans2(Node *he){//reccursion
	Node *head=he;
	if(head!=NULL){
		cout<<head->data<<endl;
		listTrans2(head->next);
	}
}
int listSearch(Node *he,int n,int i=1){//recc
	Node *head=he;
	if(head==NULL)	return -1;
	if(head->data == n)	return i;
	i++;
	return listSearch(head->next,n,i);
}
Node* insertBegin(Node *he,int n){
	Node *ne=new Node(n);
	ne->next = he;
	return ne;
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
Node* insertAfter(Node *head,int pos, int data){
	int i=1;
	Node *temp=new Node(data);
	Node *curr=head;
	while(i<pos&&curr!=NULL){
		curr=curr->next;
		i++;
	}
	temp->next=curr->next;
	curr->next=temp;
	return head;
}
Node* insertSorted(Node *head,int data){
	Node *curr = head;
	if(data<curr->data)	return insertBegin(head,data);
	Node *temp=new Node(data);
	while(curr->next != NULL && data>((curr->next)->data)){
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next=temp;
	return head;
}
Node* delFirst(Node *head){
	if(head==NULL)	 return NULL;
	Node *curr=head->next;
	delete(head);
	return curr;
}
Node* delLast(Node *head){
	if(head==NULL)	return NULL;
	Node *curr=head;
	while(curr->next->next!=NULL)	curr=curr->next;
	delete(curr->next);
	curr->next=NULL;
	return head;
}
int midNode(Node *head){ //naive
	Node *curr=head;
	int i=1;
	while(curr->next !=NULL){
		curr=curr->next;
		i+=1;
	}
	int mid=i/2+1;
	//cout<<i<<endl<<mid<<endl;
	i=1;
	curr=head;
	while(curr!=NULL){
		if(i==mid)	return curr->data;
		curr=curr->next;
		i+=1;
	}
	return -1;
}
void midNode2(struct Node *head)  //Single transe
{  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        cout<<slow_ptr->data;  
    }  
}
void nFromEnd(Node *head,int n){
	int diff=0;
	Node *curr=head,*ans=head;
	while(diff<n-1){
		if(curr==NULL)	return; //error when d=len+1
		curr=curr->next;
		diff+=1;
	}
	while(curr->next!=NULL){
		curr=curr->next;
		ans=ans->next;
	}
	// while(curr->next!=NULL){
	// 	curr=curr->next;
	// 	if(diff>=n)	ans=ans->next;
	// 	diff++;
	// }
	cout<<ans->data;
}
Node* reverse(Node *head){ //Naive
	std::vector<int> v;
	for(Node *curr=head;curr!=NULL;curr=curr->next){
		v.push_back(curr->data);
	}	
	for(Node *curr=head;curr!=NULL;curr=curr->next){
		curr->data=v.back();
		v.pop_back();
	}
	return head;
}
Node * reverse2(Node *head){ //onetrans
	Node *prev=NULL,*curr=head;
	while(curr!=NULL){
		Node *net=curr->next;
		curr->next=prev;
		prev=curr;
		curr=net;
	}
	return prev;
}
Node *reverse3(Node *head){ //recc1
	if(head==NULL)	return NULL;
	if(head->next == NULL)	return head;
	Node *rest_head=reverse3(head->next);
	Node *rest_tail=head->next;
	rest_tail->next=head;
	head->next=NULL;
	return rest_head;
}
Node *reverse4(Node *curr, Node *prev=NULL){ //recc2
	if(curr==NULL)	return prev;
	Node *next=curr->next;
	curr->next=prev;
	return reverse4(next,curr);
}
Node *removeDupli(Node *head){
	Node *curr=head;
	while(curr!=NULL &&curr->next!=NULL){
		if(curr->next->data==curr->data){
			Node *temp=curr->next;
			curr->next=curr->next->next;
			delete(temp);
			continue;
		}
		curr=curr->next;
	}
	return head;
}
int main(){
	Node *head = new Node(10);
	head -> next = new Node(20); 
	head -> next -> next = new Node(20);
	head -> next -> next ->next = new Node(20);
	cout<<head->data;
	// head=insertEnd(head,50);
	// cout<<listSearch(head,0);
	// head=insertEnd(head,5);
	// head=delFirst(head);
	// head=delLast(head);
	// head=insertAfter(head,3,10);
	// head=insertSorted(head,45);
	// cout<<midNode(head);
	// midNode2(head);
	// nFromEnd(head,6);
	// head=reverse4(head);
	// head=removeDupli(head);
	// listTrans2(head);
	return 0;
}