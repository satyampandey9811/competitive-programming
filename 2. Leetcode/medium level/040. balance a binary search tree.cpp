// link to question - https://leetcode.com/problems/balance-a-binary-search-tree/

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
    
    void store(TreeNode *root, vector<TreeNode*> &nodes){
        if(root == NULL)
            return;
        store(root -> left, nodes);
        nodes.push_back(root);
        store(root -> right, nodes);
    }
    
    TreeNode* balanced(vector<TreeNode*> &nodes, int low, int high){
        if(low > high)
            return NULL;
        int mid = low + (high - low) / 2;
        TreeNode* root = nodes[mid];
        root -> left = balanced(nodes, low, mid - 1);
        root -> right = balanced(nodes, mid + 1, high);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> nodes;
        store(root, nodes);
        int n = nodes.size();
        TreeNode *x = balanced(nodes, 0, n - 1);
        return x;
    }
};