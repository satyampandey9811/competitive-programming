// link to question - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp1 = head, *temp2 = head, *temp3 = head;
        int len = 0;
        while(temp1) {
            len++;
            temp1 = temp1 -> next;
        }
        
        int a = k, b = len - k + 1;
        int c = 1;
        
        while(temp2) {
            if(c == a) break;
            temp2 = temp2 -> next;
            c++;
        }
        c = 1;
        while(temp3) {
            if(c == b) break;
            temp3 = temp3 -> next;
            c++;
        }
        
        swap(temp2 -> val, temp3 -> val);
        return head;
    }
};