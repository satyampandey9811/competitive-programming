// link to question - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

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
    vector<int> ans;
    TreeNode* target;
    int k;
    
    void getAllNodes(TreeNode* root, int level) {
        if(!root) return;
        if(level == k) {
            ans.push_back(root -> val);
            return;
        }
        getAllNodes(root -> left, level + 1);
        getAllNodes(root -> right, level + 1);
    }
    
    pair<bool, int> findNodes(TreeNode* root) {
        if(!root) return {false, 1e9};
        if(root == target) {
            getAllNodes(root, 0);
            return {true, 1};
        }
        auto left = findNodes(root -> left);
        auto right = findNodes(root -> right);
        
        if(left.second == k or right.second == k) {
            ans.push_back(root -> val);
            return {false, 1e9};
        }
        
        if(left.first) {
            getAllNodes(root -> right, left.second + 1);
            return {true, left.second + 1};
        }
        
        if(right.first) {
            getAllNodes(root -> left, right.second + 1);
            return {true, right.second + 1};
        }
        
        return {false, -1e9};
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        this -> target = t;
        this -> k = k;
        findNodes(root);
        return ans;
    }
};