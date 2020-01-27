// link to question - https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {
        int num = -1, ans = 0;
        ListNode* temp = head;
        while(temp != NULL){
            num++;
            temp = temp -> next;
        }
        temp = head;
        while(temp != NULL){
            ans += temp->val * pow(2, num);
            num--;
            temp = temp ->next;
        }
        return ans;
    }
};