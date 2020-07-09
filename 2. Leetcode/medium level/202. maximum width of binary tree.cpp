// link to question - https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 1});
        int ans = 1, x, y;
        
        while(q.size() != 0) {                   
            int size = q.size();
        
            for(int i = 1; i <= size; i++) {
                auto node = q.front().first;
                int num = q.front().second;
                q.pop();
                if(i == 1) x = num;
                y = num;
                if(size == 1) {                    
                    if(node -> left) q.push({node -> left, 1});
                    if(node -> right) {
                        if(node -> left) q.push({node -> right, 2});
                        else q.push({node -> right, 1});
                    }                                        
                }
                else {
                    if(node -> left) q.push({node -> left, num * 2 - 1});
                    if(node -> right) q.push({node -> right, num * 2});
                }
            }                        
            
            ans = max(ans, y - x + 1);
        }
        
        return ans;       
    }
};