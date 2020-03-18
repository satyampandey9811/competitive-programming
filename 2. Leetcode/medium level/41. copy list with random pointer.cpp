// link to question - https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head) return NULL;
        
        Node *finalHead = NULL, *finalTail = NULL, *temp = head;       
        
        while(temp){
            Node *newnode = new Node(temp -> val);
            newnode -> next = temp -> next;
            temp -> next = newnode;
            temp = temp -> next -> next;
        }
        temp = head;
        
        while(temp){
            if(temp -> random)
                temp -> next -> random = temp -> random -> next;            
            temp = temp -> next -> next;
        }
        
        temp = head;
        finalHead = finalTail = temp -> next;
                
        while(finalTail and finalTail -> next){
            temp -> next = temp -> next -> next;
            finalTail -> next = finalTail -> next -> next;
            
            finalTail = finalTail -> next;
            temp = temp -> next;
        }
        temp -> next = NULL;
        return finalHead;                
    }
};