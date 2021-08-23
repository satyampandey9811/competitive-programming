// link to question - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    unordered_set<int> s;
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;
        if(s.count(k - root -> val)) return 1;
        s.insert(root -> val);
        bool left = findTarget(root -> left, k);
        if(left) return 1;
        bool right = findTarget(root -> right, k);
        return right;
    }
};