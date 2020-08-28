// link to question - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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
struct node {
    int low, high, sum;
    bool bst;
};

class Solution {
public:
    int ans;
    
    node help(TreeNode* root, char c) {
        node a;
        if(!root) {
            a.low = INT_MAX, a.high = INT_MIN, a.sum = 0;
            a.bst = true;
            return a;
        }
        
        node left = help(root -> left, 'l');
        node right = help(root -> right, 'r');
        
        bool bst = true;
        
        if(root -> val > left.high and root -> val < right.low and left.bst and right.bst) a.sum = root -> val + left.sum + right.sum;
        else a.sum = 0, bst = false;
        
        ans = max(ans, a.sum);
            
        a.low = min({root -> val, left.low, right.low});
        a.high = max({root -> val, left.high, right.high});
        a.bst = bst;
        
        return a;
    }
    
    int maxSumBST(TreeNode* root) {
        ans = 0;
        help(root, 'c');
        return ans;
    }
};