// link to question - https://leetcode.com/problems/merge-k-sorted-lists/

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
struct cell {
    ListNode *curr;
    int val;
};

class comp {
public:
    bool operator()(const cell &a, const cell &b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0), *tail = head;        
        vector<cell> a;
        
        for(int i = 0; i < lists.size(); i++) {            
            if(lists[i]) {
                cell temp;
                temp.curr = lists[i];
                temp.val = lists[i] -> val;
                a.push_back(temp);
            }
        }
        
        priority_queue<cell, vector<cell>, comp> pq;
        
        for(int i = 0; i < a.size(); i++) pq.push(a[i]);
                
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            tail -> next = p.curr;
            tail = p.curr;
            
            if(p.curr -> next) {                
                cell temp;
                temp.curr = p.curr -> next;
                temp.val = p.curr -> next -> val;
                pq.push(temp);
            }
        }
        
        return head -> next;
    }
};