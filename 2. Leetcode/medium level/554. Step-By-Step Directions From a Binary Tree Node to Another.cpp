// link to question - https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    TreeNode *lca;
    string s, d;
    
    bool findLca(TreeNode *root, int &sv, int &dv) {
        if (!root) return 0;
        if (root -> val == sv or root -> val == dv) {
            lca = root;
            return 1;
        }
        bool left = findLca(root -> left, sv, dv);
        bool right = findLca(root -> right, sv, dv);
        if(left and right) {
            lca = root;
        }
        return left or right;
    }
    
    bool findPath(TreeNode *root, int &val, char dir, string &a) {
        if (!root) return 0;
        if (root -> val == val) {
            a += dir;
            return 1;
        }
        bool left = findPath(root -> left, val, 'L', a);
        bool right = findPath(root -> right, val, 'R', a);
        
        if (left) a += dir;
        if (right) a += dir;
        return left or right;
    }
    
    string getDirections(TreeNode* root, int sv, int dv) {
        s = "";
        d = "";
        findLca(root, sv, dv);
        findPath(lca, sv, ' ', s);
        findPath(lca, dv, ' ', d);
        
        s.pop_back();
        d.pop_back();
        for (int i = 0; i < s.size(); i++) s[i] = 'U';
        reverse(d.begin(), d.end());
        return s + d;
    }
};