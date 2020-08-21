// link to question - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int ans;
    
    void go(TreeNode* root, int low, int high) {
        if(!root) return;
        
        ans = max({ans, abs(root -> val - low), abs(root -> val - high)});  
        
        go(root -> left, min(low, root -> val), max(high, root -> val));
        go(root -> right, min(low, root -> val), max(high, root -> val));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        go(root, root -> val, root -> val);
        return ans;
    }
};