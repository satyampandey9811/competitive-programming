// link to question - https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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
    int ans;
        
    vector<int> help(TreeNode* root, int d) {
        if(!root) return {};
        if(!root -> left and !root -> right) return {1};
        
        vector<int> left = help(root -> left, d);
        vector<int> right = help(root -> right, d);
        
        if(root -> left and root -> right) {            
            for(int i = 0; i < left.size(); i++) {
                for(int j = 0; j < right.size(); j++) {
                    if(left[i] + right[j] <= d) ans++;
                }
            }
        }                                        
        
        vector<int> res;
        for(int i = 0; i < left.size(); i++) res.push_back(left[i] + 1);
        for(int i = 0; i < right.size(); i++) res.push_back(right[i] + 1);
        return res;
    }
    
    int countPairs(TreeNode* root, int d) {
        ans = 0;
        vector<int> res = help(root, d);
        return ans;
    }
};