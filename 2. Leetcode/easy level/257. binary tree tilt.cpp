// link to question - https://leetcode.com/problems/binary-tree-tilt/

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
    int ans = 0;
    
    int go(TreeNode* root) {
        if(!root) return 0;
        int left = go(root -> left);
        int right = go(root -> right);
        ans += abs(left - right);
        left += root -> val + right;
        return left;
    }
    
    int findTilt(TreeNode* root) {
        go(root);
        return ans;
    }
};