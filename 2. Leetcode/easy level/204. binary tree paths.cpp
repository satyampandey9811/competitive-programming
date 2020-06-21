// link to question - https://leetcode.com/problems/binary-tree-paths/

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
    void help(TreeNode* root, vector<string> &ans, string s) {
        if(!root) return;
        s += to_string(root -> val);
        if(!root -> left and !root -> right) {
            ans.push_back(s);
        } else {
            help(root -> left, ans, s + "->");
            help(root -> right, ans, s + "->");
        }        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {                        
        vector<string> ans; 
        help(root, ans, "");
        return ans;
    }
};