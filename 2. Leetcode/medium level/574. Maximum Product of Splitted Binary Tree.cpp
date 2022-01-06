// link to question - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    long long sum, ans = 1;
    int mod = 1e9 + 7;
    
    int getSum (TreeNode* root) {
        if (!root) return 0;
        return getSum(root -> left) + getSum(root -> right) + root -> val;
    }
    
    int findAnswer (TreeNode* root) {
        int left = 0, right = 0;
        if (root -> left) {
            left = findAnswer(root -> left);
            ans = max(ans, left * 1LL * (sum - left));
        }
        if (root -> right) {
            right = findAnswer(root -> right);
            ans = max(ans, right * 1LL * (sum - right));
        }
        
        return left + right + root -> val;
    }
    
    int maxProduct(TreeNode* root) {
        sum = getSum(root);
        findAnswer(root);
        return ans % mod;
    }
};