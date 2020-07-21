// link to question - https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int val = INT_MIN, size = q.size();
            for(int i = 0; i < size; i++) {
                auto front = q.front();
                val = max(val, front -> val);
                q.pop();
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            ans.push_back(val);
        }
        
        return ans;
    }
};