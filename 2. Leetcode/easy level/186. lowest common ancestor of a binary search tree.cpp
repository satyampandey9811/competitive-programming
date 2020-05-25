// link to question - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p or root == q)
            return root;
        bool findp = false, findq = false;
        if(p -> val < root -> val) findp = true;
        if(q -> val < root -> val) findq = true;
        if((findp and !findq) or (!findp and findq))
            return root;
        if(findp and findq)
            return lowestCommonAncestor(root -> left, p, q);
        else
            return lowestCommonAncestor(root -> right, p, q);
    }
};