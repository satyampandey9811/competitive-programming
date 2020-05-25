// link to question - https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* help(vector<int>& a, int s, int e) {
        if(s > e) return NULL;
        int ind, maxval = INT_MIN;
        for(int i = s; i <= e; i++) {
            if(a[i] > maxval) 
                ind = i, maxval = a[i];            
        }
        TreeNode* root = new TreeNode(maxval);
        root -> left = help(a, s, ind - 1);
        root -> right = help(a, ind + 1, e);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return help(nums, 0, nums.size() - 1);
    }
};