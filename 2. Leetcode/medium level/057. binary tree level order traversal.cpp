// link to question - https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* front = q.front();        
            q.pop();
            if(front == NULL){
                if(q.empty()){
                    ans.push_back(temp);
                    break;
                }  
                else{                    
                    q.push(NULL);
                    ans.push_back(temp);
                    temp = {};
                    continue;
                }
            }
            temp.push_back(front -> val);
            if(front -> left)
                q.push(front -> left);
            if(front -> right)
                q.push(front -> right);
        }
        return ans;
    }
};