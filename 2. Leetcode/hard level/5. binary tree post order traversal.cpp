// link to question - https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<int> a;
        stack<TreeNode*> s;
        s.push(root);        
            
        while(s.size() != 0){
            TreeNode* top = s.top();
            s.pop();      
            a.push_back(top -> val);
            if(top -> left)
                s.push(top -> left);
            if(top -> right)
                s.push(top -> right);
        }            
        reverse(a.begin(), a.end());
        return a;
    }
};