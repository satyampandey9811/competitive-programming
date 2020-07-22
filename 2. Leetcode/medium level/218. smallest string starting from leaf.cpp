// link to question - https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string a;
    
    void help(TreeNode* root, string s) {
        if(!root) return;
        s += 'a' + root -> val;
        if(!root -> left and !root -> right) {
            reverse(s.begin(), s.end());
            if(a.size() == 0) a = s;
            else if(s < a) a = s;
            return;
        }
        help(root -> left, s);
        help(root -> right, s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        help(root, "");
        return a;
    }
};