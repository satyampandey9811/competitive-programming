// link to question - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* helper(vector<int>& a, int s, int e){
        if(s > e) return NULL;
        if(s == e){
            return new TreeNode(a[s]);
        }
        TreeNode *root = new TreeNode(a[s]);
        int id;
        for(id = s + 1; id <= e; id++){
            if(a[id] > a[s])
                break;
        }
        root->left = helper(a, s + 1, id - 1);
        root->right = helper(a, id, e);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {                        
        return helper(preorder, 0, preorder.size() - 1);        
    }
};