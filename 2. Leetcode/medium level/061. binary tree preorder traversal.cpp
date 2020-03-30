// link to question - https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        
        while(s.size() != 0){
            TreeNode* top = s.top();
            s.pop();
            ans.push_back(top -> val);
            if(top -> right) s.push(top -> right);
            if(top -> left) s.push(top -> left);            
        }
        return ans;
    }
};