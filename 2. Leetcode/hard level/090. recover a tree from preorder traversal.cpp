// link to question - https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
    int n;
    
    pair<TreeNode*, int> go(int depth, int &i, string &a) {
        int num = 0;
        while(i < n and a[i] != '-') {
            num *= 10;
            num += a[i] - '0';
            i++;
        }
        
        TreeNode *root = new TreeNode(num);
        
        int dash = 0;
        while(i < n and a[i] == '-') {
            dash++;
            i++;
        }
        
        pair<TreeNode*, int> ans;
        
        if(dash == depth + 1) {
            ans = go(depth + 1, i, a);
            root -> left = ans.first;
            if(ans.second == dash) {
                ans = go(depth + 1, i, a);
                root -> right = ans.first;
            }
        }
        else ans = {root, dash};
        ans.first = root;
        return ans;
    }
    
    TreeNode* recoverFromPreorder(string a) {
        int i = 0;
        n = a.size();
        return go(0, i, a).first;
    }
};