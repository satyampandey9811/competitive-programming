// link to question - https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem



// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

int length(SinglyLinkedListNode* temp){
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    int m=length(head1),n=length(head2);
    int c=m-n;
    if(n>m){
        SinglyLinkedListNode* temp=head1;
        head1=head2;
        head2=temp;
        c=n-m;
    }
    for(int i=0;i<c;i++) head1=head1->next;
    while(head1!=NULL){
        if(head1==head2) return head1->data;
        head1=head1->next;
        head2=head2->next;
    }
    return 0;
}

