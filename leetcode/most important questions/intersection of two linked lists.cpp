// link to question - https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* temp){
        int l=0;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        return l;
    }   
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=length(headA), n=length(headB);
        int d=m-n;
        if(n>m){
            ListNode *temp=headA;
            headA=headB;
            headB=temp;
            d=n-m;
        }
        for(int i=0;i<d;i++) headA=headA->next;
        while(headA!=NULL){
            if(headA==headB)
                return headA;   
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};

