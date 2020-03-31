// link to question - https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int ans = 0;    
    
    void helper(TreeNode* root, int res = 0){
        if(root == NULL)
            return;                    
        res = res * 2 + root -> val;
        helper(root -> left, res);                                        
        helper(root -> right, res);                                  
        if(!root -> left and !root -> right)
            ans += res;        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        helper(root);
        return ans;
    }
};