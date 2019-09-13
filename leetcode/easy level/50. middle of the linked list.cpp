// link to question - https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        int c=0;
        auto temp=head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        int mid=c/2+1;
        int i=1;
        temp=head;
        while(i<mid){
            temp=temp->next;
            i++;
        }
        return temp;
    }
};