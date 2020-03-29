// link to question - https://leetcode.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, bool &ans){
        if(root == NULL)
            return 0;
        int a = height(root -> left, ans);
        int b = height(root -> right, ans);
        if(a < b) swap(a, b);
        if(a - b > 1) ans = false;
        return 1 + max(a, b);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int a = height(root, ans);
        return ans;
    }
};