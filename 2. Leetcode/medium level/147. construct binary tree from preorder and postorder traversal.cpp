// link to question - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
    TreeNode* f(vector<int>& pre, vector<int>& post, int preS, int preE, int postS, int postE) {
        if(preS > preE) return NULL;
        TreeNode* root = new TreeNode(pre[preS]);
        
        if(preS == preE) {
            root -> left = root -> right = NULL;
            return root;
        }
        
        int index = -1;
        for(int i = postS; i <= postE; i++) {            
            if(post[i] == pre[preS + 1]) {
                index = i;
                break;
            }
        }
                
        int lPostS = postS;
        int lPostE = index;
        int lPreS = preS + 1;
        int lPreE = lPostE - lPostS + lPreS;
        int rPreS = lPreE + 1;
        int rPreE = preE;        
        int rPostS = lPostE + 1;
        int rPostE = postE - 1;
        
        root -> left = f(pre, post, lPreS, lPreE, lPostS, lPostE);
        root -> right = f(pre, post, rPreS, rPreE, rPostS, rPostE);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return f(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }
};