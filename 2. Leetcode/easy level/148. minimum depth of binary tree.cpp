// link to question - https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;        
        int a = minDepth(root -> left);
        int b = minDepth(root -> right);
        int ans = 1;
        if(a and b) ans += min(a, b);
        else if(a and !b) ans += a;
        else if(!a and b) ans += b;        
        return ans;
    }
};