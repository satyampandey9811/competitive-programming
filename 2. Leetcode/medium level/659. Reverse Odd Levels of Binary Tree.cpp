// link to question - https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    vector<vector<int>> a;
    
    void go (TreeNode* root, int l) {
        if (!root) return;
        if (a.size() <= l) a.push_back({});
        a[l].push_back(root -> val);
        go(root -> left, l + 1);
        go(root -> right, l + 1);
    }
    
    void goa (TreeNode* root, int l, int i) {
        if (!root) return;
        root -> val = a[l][i];
        goa(root -> left, l + 1, 2 * i);
        goa(root -> right, l + 1, 2 * i + 1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        go(root, 0);
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (i & 1) reverse(a[i].begin(), a[i].end());
            for (auto &j :a[i]) cout << j << ' ';
            cout << endl;
        }
        goa(root, 0, 0);
        return root;
    }
};