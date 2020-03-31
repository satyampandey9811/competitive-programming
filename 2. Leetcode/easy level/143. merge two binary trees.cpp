// link to question - https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) return t2;        
        if(t2 == NULL) return t1;  
        
        queue<pair<TreeNode*, TreeNode*>> q;
        TreeNode *a, *b;
        q.push({t1, t2});
        t1 -> val += t2 -> val;                
        
        while(q.size() != 0){
            pair<TreeNode*, TreeNode*> front = q.front();
            q.pop();
            a = front.first;
            b = front.second;
        
            if(a -> left and b -> left){
                a -> left -> val += b -> left -> val;
                q.push({a -> left, b -> left});                
            } 
            else if(!a -> left and b -> left)
                a -> left = b -> left;
            
            if(a -> right and b -> right){
                a -> right -> val += b -> right -> val;
                q.push({a -> right, b -> right});
            }
            else if(!a -> right and b -> right)
                a -> right = b -> right;            
        }                
        return t1;
    }
};