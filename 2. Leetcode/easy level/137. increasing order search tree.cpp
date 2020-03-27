// link to question - https://leetcode.com/problems/increasing-order-search-tree/

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
    vector<TreeNode*> a;
    void helper(TreeNode* root){
        if(root == NULL)
            return;
        helper(root -> left);
        a.push_back(root);
        helper(root -> right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        root = a[0];
        for(int i = 0; i < a.size(); i++){
            a[i] -> left = NULL;
            if(i != a.size() - 1)
                a[i] -> right = a[i + 1];
            else
                a[i] -> right = NULL;            
        }
        return root;
    }
};