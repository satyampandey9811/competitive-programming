// link to question - https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *curr = NULL;
        if(root) s.push(root), curr = root -> left;        
        
        while(curr or s.size()) {
            while(curr) {
                s.push(curr);
                curr = curr -> left;
            }  
            
            auto top = s.top();
            ans.push_back(top -> val);
            s.pop();
            curr = top -> right;
        }
        
        return ans;
    }    
};