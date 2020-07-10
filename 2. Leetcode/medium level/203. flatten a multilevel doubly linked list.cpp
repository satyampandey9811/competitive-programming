// link to question - https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:    
    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp) {
            if(temp -> child) {
                Node *childTail = temp -> child;
                while(childTail -> next) childTail = childTail -> next;
                childTail -> next = temp -> next;
                if(temp -> next) temp -> next -> prev = childTail;
                temp -> next = temp -> child;
                temp -> child -> prev = temp;
                temp -> child = NULL;
            }
            temp = temp -> next;
        }
        return head;
    }
};