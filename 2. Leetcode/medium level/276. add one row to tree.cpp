// link to question - https://leetcode.com/problems/add-one-row-to-tree/

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
    void dfs(TreeNode* root, int v, int d, int depth) {
        if(!root) return;
        if(depth + 1 == d) {
            TreeNode* leftnode = new TreeNode(v);
            TreeNode* rightnode = new TreeNode(v);
            leftnode -> left = root -> left;
            rightnode -> right = root -> right;
            root -> left = leftnode;
            root -> right = rightnode;
            return;
        }
        dfs(root -> left, v, d, depth + 1);
        dfs(root -> right, v, d, depth + 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* newnode = new TreeNode(v);
            newnode -> left = root;
            return newnode;
        }
        dfs(root, v, d, 1);
        return root;
    }
};