// link to question - https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem



// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* temp1= (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    temp1->data=data;
    temp1->next=NULL;
    if(head==NULL){
        head=temp1;
        return head;
    }
    SinglyLinkedListNode* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp1;
    return head;
}

