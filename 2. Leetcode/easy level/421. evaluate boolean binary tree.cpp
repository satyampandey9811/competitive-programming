// link to question - https://leetcode.com/problems/evaluate-boolean-binary-tree/

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
    bool evaluateTree(TreeNode* root) {
        if (!root -> left) return root -> val;
        bool left = evaluateTree(root -> left);
        bool right = evaluateTree(root -> right);
        if (root -> val == 2) return left or right;
        return left and right;
    }
};