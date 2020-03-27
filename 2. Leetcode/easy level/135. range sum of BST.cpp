// link to question - https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int l, int r) {
        if(root == NULL)
            return 0;
        int ans = 0;        
        if(root -> val >= l and root -> val <= r){
            ans += root -> val;
            ans += rangeSumBST(root -> left, l, r);
            ans += rangeSumBST(root -> right, l, r);
        }
        else if(root -> val < l)
            ans += rangeSumBST(root -> right, l, r);
        else 
            ans += rangeSumBST(root -> left, l, r);
        return ans;        
    }
};