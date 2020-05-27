// link to question - https://leetcode.com/problems/path-sum-ii/

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
    void help(TreeNode* root, int sum, int s, vector<vector<int>> &ans, vector<int> &temp) {
        if(root == NULL)
            return;
        s += root -> val;
        temp.push_back(root -> val);
        if(sum == s and !root -> left and !root -> right) 
            ans.push_back(temp);            
        else {        
            help(root -> left, sum, s, ans, temp);
            help(root -> right, sum, s, ans, temp);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(root, sum, 0, ans, temp);
        return ans;
    }
};