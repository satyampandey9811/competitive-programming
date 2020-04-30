// link to question - https://leetcode.com/problems/Check-If-a-String-Is-a-Valid-Sequence-from-Root-to-Leaves-Path-in-a-Binary-Tree/

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
    bool isValidSequence(TreeNode* root, vector<int>& a, int i = 0) {
        if(root == NULL or i >= a.size()) 
            return 0;
        if(root->val != a[i]) 
            return 0;            
        if(!root->left and !root->right and i + 1 == a.size()) 
            return 1;
        return isValidSequence(root->left, a, i + 1) or isValidSequence(root->right, a, i + 1);
    }
};