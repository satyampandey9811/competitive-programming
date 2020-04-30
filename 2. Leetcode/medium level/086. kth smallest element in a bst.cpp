// link to question - https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int ans, c;
    void helper(TreeNode* root, int k){
        if(root == NULL or c > k)
            return;        
        helper(root -> left, k);
        c++;
        if(c == k){
            ans = root -> val;
            return;
        }
        helper(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        c = 0;
        return ans;
    }
};