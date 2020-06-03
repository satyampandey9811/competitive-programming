// link to question - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* f(vector<int>& in, vector<int>& post, int inS, int inE, int postS, int postE) {
        if(inS > inE) return NULL;
        TreeNode* root = new TreeNode(post[postE]);
        int index = -1;
        for(int i = inS; i <= inE; i++) {
            index = i;
            if(in[i] == root -> val) break;
        }
        
        int lInS = inS;
        int lInE = index - 1;
        int lPostS = postS;
        int lPostE = lInE - lInS + lPostS;
        int rInS = index + 1;
        int rInE = inE;
        int rPostS = lPostE + 1;
        int rPostE = postE - 1;
        
        root -> left = f(in, post, lInS, lInE, lPostS, lPostE);
        root -> right = f(in, post, rInS, rInE, rPostS, rPostE);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return f(inorder, postorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
    }
};