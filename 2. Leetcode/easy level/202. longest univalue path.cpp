// link to question - https://leetcode.com/problems/longest-univalue-path/

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
    
    int find(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = find(root -> left);
        int right = find(root -> right);
        int curr = root -> val;
        
        if(root -> left and root -> right) {
            if(curr == root -> left -> val and curr == root -> right -> val){
                ans = max(ans, 2 + left + right);
                return 1 + max(left, right);
            }
        }
        
        if(root -> left and curr == root -> left -> val) {
            ans = max(ans, 1 + left);
            return 1 + left;
        }
        
        if(root -> right and curr == root -> right -> val) {
            ans = max(ans, 1 + right);
            return 1 + right;
        }
        
        return 0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        ios::sync_with_stdio(false), cin.tie(0);
        ans = 0;
        find(root);
        return ans;
    }
};