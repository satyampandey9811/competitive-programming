// link to question - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res, ans = INT_MIN, sum, level = 1;
        
        while(q.size()) {
            sum = 0;
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto front = q.front();
                q.pop();
                sum += front -> val;
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }
            if(ans < sum) {
                ans = sum;
                res = level;
            }
            level++;
        }
        
        return res;
    }
};