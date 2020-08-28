// link to question - https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    
    int helper(TreeNode* root){
        if(root == NULL) 
            return 0;
        
        int left = helper(root -> left);
        int right = helper(root -> right);
        int curr = root -> val;
                 
        ans = max({ans, curr, left + curr, right + curr, left + curr + right});
        
        return max({left + curr, curr, right + curr});
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        int a = helper(root);
        return ans;
    }
};