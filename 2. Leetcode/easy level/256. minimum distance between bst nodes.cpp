// link to question - https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    int ans = INT_MAX;
    
    void go(TreeNode* root, int& val) {
        if(!root) return;
        go(root -> left, val);
        ans = min(ans, abs(root -> val - val));
        val = root -> val;
        go(root -> right, val);
    }
    
    int minDiffInBST(TreeNode* root) {
        int val = 1e6;
        go(root, val);
        return ans;
    }
};