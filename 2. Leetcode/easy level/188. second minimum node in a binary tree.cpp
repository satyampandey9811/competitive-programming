// link to question - https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    int findMin(TreeNode* root) {
        if(root == NULL)
            return INT_MAX;
        return min({root -> val, findMin(root -> left), findMin(root -> right)});
    }
    
    void findSecondMin(TreeNode* root, int minval, long long int &ans) {
        if(root == NULL) 
            return;
        if(root -> val > minval and root -> val < ans)
            ans = root -> val;
        findSecondMin(root -> left, minval, ans);
        findSecondMin(root -> right, minval, ans);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int minval = findMin(root);
        long long int ans = LLONG_MAX;
        findSecondMin(root, minval, ans);
        return ans == LLONG_MAX ?-1 : ans;
    }
};