// link to question - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> temp;
        bool flag = true;
        q.push(root);
        q.push(NULL);

        while(q.size() != 0){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                if(q.empty()){
                    if(!flag)
                        reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                    break;
                }
                else{
                    if(!flag){
                        flag = true;
                        reverse(temp.begin(), temp.end());
                    }
                    else
                        flag = false;
                    ans.push_back(temp);
                    temp = {};
                    q.push(NULL);                
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