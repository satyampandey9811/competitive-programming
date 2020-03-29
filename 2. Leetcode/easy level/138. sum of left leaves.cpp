// link to question - https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root or (!root -> left and !root -> right))
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        
        while(q.size() != 0){
            TreeNode* front = q.front();
            q.pop();
            
            if(front -> left){
                q.push(front -> left);
                if(!front -> left -> left and !front -> left -> right)
                    sum += front -> left -> val;
            }
            if(front -> right)
                q.push(front -> right);
        }
        return sum;
    }
};