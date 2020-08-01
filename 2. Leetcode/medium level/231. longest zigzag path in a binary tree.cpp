// link to question - https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

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
    
    int dfs(TreeNode* root, char dir) {
        if(!root) return 0;
        int left = dfs(root -> left, 'l');
        int right = dfs(root -> right, 'r');
        ans = max({ans, left, right});
        if(dir == 'l') return right + 1;
        else return left + 1;
    }
    
    int longestZigZag(TreeNode* root) {
        ans = 0;
        dfs(root, 'c');
        return ans;
    }
};