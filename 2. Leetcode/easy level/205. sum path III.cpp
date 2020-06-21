// link to question - https://leetcode.com/problems/path-sum-iii/

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
    unordered_map<int, int> store;
    
    int help(TreeNode* root, int &sum, int pre){
        if (!root) return 0;
        root -> val += pre;
        
        int res = (root -> val == sum);
        res += (store.count(root -> val - sum) ? store[root -> val - sum] : 0);
        
        store[root -> val]++;
        
        res += help(root -> left, sum, root -> val);
        res += help(root -> right, sum, root -> val);
        
        store[root -> val]--;
        
        return res;
    }

    int pathSum(TreeNode* root, int sum) {        
        return help(root, sum, 0);
    }
};