// link to question - https://leetcode.com/problems/merge-in-between-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1 = list1, *temp2, *temp3;
        int i = 0;
        
        while(temp1) {
            temp2 = temp1;
            i++;
            if(i == a) break;
            temp1 = temp1 -> next;
        }
        temp1 = list1;
        b += 2;
        i = 0;
        while(temp1) {
            temp3 = temp1;
            i++;
            if(i == b) break;
            temp1 = temp1 -> next;
        }
        
        temp2 -> next = list2;
        ListNode *temp = list2;
        
        while(temp) {
            if(temp -> next == NULL) break;
            temp = temp -> next;
        }
        
        temp -> next = temp1;
        return list1;
    }
};