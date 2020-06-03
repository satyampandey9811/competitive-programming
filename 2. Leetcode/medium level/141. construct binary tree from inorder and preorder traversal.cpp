// link to question - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* f(vector<int>& pre, vector<int>& in, int preS, int preE, int inS, int inE) {
        if(inS > inE or preS > preE) return NULL;        
        TreeNode* root = new TreeNode(pre[preS]);
        int index = -1;
        for(int i = inS; i <= inE; i++) {            
            if(in[i] == root -> val) {
                index = i;
                break;
            }
        }
                
        int lInS = inS;
        int lInE = index - 1;
        int lPreS = preS + 1;
        int lPreE = lInE - lInS + lPreS;
        int rPreS = lPreE + 1;
        int rPreE = preE;        
        int rInS = index + 1;
        int rInE = inE;
        
        root -> left = f(pre, in, lPreS, lPreE, lInS, lInE);
        root -> right = f(pre, in, rPreS, rPreE, rInS, rInE);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(preorder, inorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
    }
};