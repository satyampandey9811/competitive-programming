// link to question - https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned == NULL)
            return NULL;
        if(cloned -> val == target -> val)
            return cloned;
        auto left = getTargetCopy(original, cloned -> left, target);
        auto right = getTargetCopy(original, cloned -> right, target);
        if(left) return left;
        return right;
    }
};