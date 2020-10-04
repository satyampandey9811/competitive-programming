// link to question - https://leetcode.com/problems/even-odd-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, min, max, e;
        
        while(q.size()) {
            int size = q.size();            
            min = INT_MIN, max = INT_MAX;
            
            for(int i = 0; i < size; i++) {
                auto front = q.front();                
                q.pop();
                e = front -> val;                
                
                if(level & 1) {
                    if(e & 1) return 0;
                    if(e >= max) return 0;
                    max = e;
                }    
                else {
                    if(e % 2 == 0) return 0;
                    if(e <= min) return 0;
                    min = e;
                }
                
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            
            level++;
        }
        
        return 1;
    }
};