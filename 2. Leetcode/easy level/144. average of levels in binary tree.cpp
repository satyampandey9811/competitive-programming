// link to question - https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    void helper(TreeNode *root, vector<pair<double,int>> &levels,int level){
        if(root == NULL) return;
        if(levels.size() == level){
            pair<double, int> p;
            p.first = root -> val;
            p.second = 1;
            levels.push_back(p);
        }
        else{
            levels[level].first += root -> val;
            levels[level].second++;
        }
        helper(root -> left, levels, level + 1);
        helper(root -> right, levels, level + 1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<pair<double, int>> levels;
        helper(root, levels, 0);
        vector<double> ans;
        for(int i = 0; i < levels.size(); i++)
            ans.push_back(levels[i].first / levels[i].second);
        return ans;
    }
};