// link to question - https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int ans;
    unordered_map<int, int> m;
    
    bool check() {        
        int c = 0, odd = 0, even = 0;
        for(auto i: m) {
            c += i.second;
            if(i.second & 1) odd++;
            else even++;
        }
        if(c & 1) {
            return odd == 1;
        }
        else {
            return odd == 0;
        }
    }
    
    void helper(TreeNode *root) {
        if(root == NULL)
            return;
        m[root -> val]++;
        if(!root -> left and !root -> right) {
            if(check()) ans++;
            m[root -> val]--;
            return;
        }            
        helper(root -> left);
        helper(root -> right);
        m[root -> val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};