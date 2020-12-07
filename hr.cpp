SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *curr1=head1,*curr2=head2,*nex;
    if(curr1->data < curr2 -> data){
        nex->data=curr1->data;
        curr1=curr1->next;
    }
    else{
        nex->data=curr2->data;
        curr2=curr2->next;
    }
    while(curr1->next!=NULL && curr2->next !=NULL){
    if(curr1->data < curr2 -> data){
        nex->next=curr1;
        curr1=curr1->next;
    }
    else{
        nex->next = curr2;
        curr2=curr2->next;
    }
    }
    if(curr1->next !=NULL){
        nex->next=curr1->next;
    }
    else if(curr2->next !=NULL){
        nex->next=curr2->next;
    }
    return nex;
}
