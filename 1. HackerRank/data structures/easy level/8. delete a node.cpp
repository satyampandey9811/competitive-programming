// link to question - https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem



// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode* temp=head;
    if(position==0){
        head=temp->next;
        free(temp);
        return head;
    }
    for(int i=1;i<=position-1;i++)
        temp=temp->next;
    SinglyLinkedListNode* temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return head;
}

