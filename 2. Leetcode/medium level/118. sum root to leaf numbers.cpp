// link to question - https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void help(TreeNode* root, long long int &ans, int n) {
        if(root == NULL)                         
            return;
        n = n * 10 + root -> val;
        if(!root -> left and !root -> right) {
            ans += n;
            return;
        }
        help(root -> left, ans, n);
        help(root -> right, ans, n);        
    }
    
    int sumNumbers(TreeNode* root) {
        long long int ans = 0;
        help(root, ans, 0);
        return ans;
    }
};