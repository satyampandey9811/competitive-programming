// link to question - https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> gen(int i, int j) {
        if(i > j) return {NULL};
        if(i == j) {
            TreeNode* node = new TreeNode(i);
            return {node};
        }
        
        vector<TreeNode*> ans;
        
        for(int k = i; k <= j; k++) {
            auto left = gen(i, k - 1);
            auto right = gen(k + 1, j);
            
            int ls = left.size(), rs = right.size();
            for(int x = 0; x < ls; x++) {
                for(int y = 0; y < rs; y++) {
                    TreeNode *node = new TreeNode(k);
                    node -> left = left[x];
                    node -> right = right[y];
                    ans.push_back(node);
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return gen(1, n);
    }
};