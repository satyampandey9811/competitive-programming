// link to question - https://leetcode.com/problems/subtree-of-another-tree/

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
    bool help(TreeNode* s, TreeNode* t) {
        if(!s and !t) return 1;
        if(!s or !t) return 0;
        if(s -> val != t -> val) return 0;
        return help(s -> left, t -> left) and help(s -> right, t -> right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s or !t) return 0;
        return help(s, t) or isSubtree(s -> left, t) or isSubtree(s -> right, t);
    }
};