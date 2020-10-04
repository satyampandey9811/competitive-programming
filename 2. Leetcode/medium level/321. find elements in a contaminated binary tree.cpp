// link to question - https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements {
public:
    unordered_set<int> s;
    
    void fill(TreeNode* root, int val) {
        if(!root) return;
        root -> val = val;
        s.insert(val);
        fill(root -> left, val * 2 + 1);
        fill(root -> right, val * 2 + 2);
    }
    
    FindElements(TreeNode* root) {
        fill(root, 0);
    }
    
    bool find(int target) {
        if(s.count(target)) return 1;
        return 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */