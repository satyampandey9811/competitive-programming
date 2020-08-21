// link to question - https://leetcode.com/problems/all-possible-full-binary-trees/

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
    vector<TreeNode*> allPossibleFBT(int n) {    
        if (n < 2) {
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        
        vector<TreeNode*> ans;
        
        for (int i = 2; i < n; i += 2) {            
            auto left = allPossibleFBT(i - 1);
            auto right = allPossibleFBT(n - i); 
        
            for (auto j: left) {
                for (auto k: right) {
                    TreeNode* root = new TreeNode(0);
                    root -> left = j;
                    root -> right = k;
                    ans.push_back(root);
                }
            }                                    
        }        
        
        return ans;           
    }
};