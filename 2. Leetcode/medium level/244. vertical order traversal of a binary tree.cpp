// link to question - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    map<int, set<pair<int, int>>> m;
        
    void help(TreeNode* root, int x, int level) {
        if(!root) return;
        m[x].insert({level, root -> val});
        help(root -> left, x - 1, level + 1);
        help(root -> right, x + 1, level + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        help(root, 0, 0);    
        vector<vector<int>> ans;
        for(auto i: m) {
            vector<int> temp;
            for(auto j: i.second) temp.push_back(j.second);
            ans.push_back(temp);
        }
        return ans;
    }
};