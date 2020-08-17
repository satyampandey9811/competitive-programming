// link to question - https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    unordered_set<int> s;
    vector<TreeNode*> ans;
    
    TreeNode* help(TreeNode* root, int parent) {
        if(!root) return NULL;
        root -> left = help(root -> left, root -> val);
        root -> right = help(root -> right, root -> val);
        
        if(s.count(root -> val)) return NULL;       
        if(s.count(parent)) ans.push_back(root);
        if(parent == -1) ans.push_back(root);
        
        return root;        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i: to_delete) s.insert(i);    
        help(root, -1);
        return ans;
    }
};