// link to question - https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem



// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
SinglyLinkedListNode* temp1= (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    temp1->data=data;
    temp1->next=NULL;
    SinglyLinkedListNode* temp=head;
    for(int i=0;i<position-1;i++)
        temp=temp->next;
    temp1->next=temp->next;
    temp->next=temp1;
    return head;
}

