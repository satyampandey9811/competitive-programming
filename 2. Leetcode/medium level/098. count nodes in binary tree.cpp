// link to question - https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    
    void help(TreeNode* root, int val) {
        if(root == NULL)
            return;
        if(root -> val >= val) ans++;
        help(root -> left, max(root -> val, val));
        help(root -> right, max(root -> val, val));
    }
    
    int goodNodes(TreeNode* root) {
        help(root, root -> val);
        return ans;    
    }
};