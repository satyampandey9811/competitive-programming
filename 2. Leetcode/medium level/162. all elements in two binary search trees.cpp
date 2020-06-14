// link to question - https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    void store(TreeNode* root, vector<int>& v) {
        if(!root) return;
        store(root -> left, v);
        v.push_back(root -> val);        
        store(root -> right, v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, ans;        
        store(root1, a);
        store(root2, b);
        
        int i = 0, j = 0;
        while(i < a.size() and j < b.size()) {
            if(a[i] < b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);            
        }
        while(i < a.size()) ans.push_back(a[i++]);
        while(j < b.size()) ans.push_back(b[j++]);
        
        return ans;
    }
};