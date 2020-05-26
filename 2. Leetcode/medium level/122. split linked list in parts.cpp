// link to question - https://leetcode.com/problems/split-linked-list-in-parts/

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
    int findSize(ListNode* root) {
        int s = 0;
        while(root != NULL) {
            s++;
            root = root -> next;
        }
        return s;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = findSize(root);
        int a = size / k, b = size % k, c = 0;
        a++;
        vector<ListNode*> ans;
        auto temp = root;
        
        while(root != NULL) {
            if(b == 0) b--, a--;            
            if(c == 0)
                ans.push_back(root);
            c++;
            temp = root;
            root = root -> next;
            if(c == a) {
                temp -> next = NULL;
                c = 0;
                b--;
            }
        }
        
        while(ans.size() != k) {
            ans.push_back({});
        }
        return ans;
    }
};