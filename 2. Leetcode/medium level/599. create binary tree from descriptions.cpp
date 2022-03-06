// link to question - https://leetcode.com/problems/create-binary-tree-from-descriptions/

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
vector<TreeNode*> store(100001);
vector<bool> child(100001);

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        TreeNode *root;
        int n = a.size();
        for (int i = 1; i < 100001; i++) {
            store[i] = NULL;
            child[i] = false;
        }
        
        for (int i = 0; i < n; i++) {
            child[a[i][1]] = true;
        }
        
        for (int i = 0; i < n; i++) {
            int pval = a[i][0], cval = a[i][1], l = a[i][2];
            
            if (store[pval] == NULL) {
                store[pval] = new TreeNode(pval);
            }
            if (store[cval] == NULL) {
                store[cval] = new TreeNode(cval);
            }
            
            if (l) store[pval] -> left = store[cval];
            else store[pval] -> right = store[cval];
        }
        
        for (int i = 0; i < n; i++) {
            if (!child[a[i][0]]) {
                root = store[a[i][0]];
                break;
            }
        }
        
        return root;
    }
};