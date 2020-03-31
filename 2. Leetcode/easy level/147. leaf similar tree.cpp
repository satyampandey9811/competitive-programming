// link to question - https://leetcode.com/problems/leaf-similar-trees/

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
    vector<int> a, b;
    
    void helper(TreeNode* root, vector<int> &v){
        if(root == NULL)
            return;
        if(!root -> left and !root -> right){
            v.push_back(root -> val);
            return;
        }
        helper(root -> left, v);
        helper(root -> right, v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(root1, a);
        helper(root2, b);
        if(a.size() != b.size())
            return false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};