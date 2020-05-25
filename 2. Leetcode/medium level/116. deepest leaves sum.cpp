// link to question - https://leetcode.com/problems/deepest-leaves-sum/

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
    void findDepth(TreeNode* root, int &depth, int level){
        if(root == NULL)
            return;
        if(level > depth) depth = level;
        findDepth(root -> left, depth, level + 1);
        findDepth(root -> right, depth, level + 1);
    }
    
    void findSum(TreeNode* root, int depth, int level, int &ans) {
        if(root == NULL)
            return;
        if(level == depth) ans += root -> val;
        findSum(root -> left, depth, level + 1, ans);
        findSum(root -> right, depth, level + 1, ans);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        findDepth(root, depth, 0);
        int ans = 0;
        findSum(root, depth, 0, ans);
        return ans;
    }
};