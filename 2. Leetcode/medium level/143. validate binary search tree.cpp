// link to question - https://leetcode.com/problems/validate-binary-search-tree/

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
    bool help(TreeNode* root, long long int minval, long long int maxval) {
        if(root == NULL) return 1;
        if(root -> val <= minval or root -> val >= maxval) return 0;
        return help(root -> left, minval, root -> val) and
               help(root -> right, root -> val, maxval);
    }
    
    bool isValidBST(TreeNode* root) {
        return help(root, LLONG_MIN, LLONG_MAX);
    }
};