// link to question - https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int sum, int currSum = 0) {   
        if(root == NULL)
            return 0;
        currSum += root -> val;
        if(currSum == sum and !root -> left and !root -> right)             
            return 1;        
        return hasPathSum(root -> left, sum, currSum) or 
               hasPathSum(root -> right, sum, currSum);
    }
};