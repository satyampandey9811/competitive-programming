// link to question - https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem



// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* temp1= (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    temp1->data=data;
    temp1->next=llist;
    llist=temp1;    
    return llist;
}

