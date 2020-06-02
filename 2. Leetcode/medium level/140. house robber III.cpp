// link to question - https://leetcode.com/problems/house-robber-iii/

class Solution {
public:  
    // pair.first stores value including root -> val
    // pair.second stores value without including root -> val
    
    pair<int, int> help(TreeNode* root) {        
        if(!root) return {0, 0};
        pair<int, int> left = help(root -> left);
        pair<int, int> right = help(root -> right);
        pair<int, int> p;
        p.first = root -> val + left.second + right.second;
        p.second = max(left.first, left.second) + max(right.first, right.second);
        return p;
    }
    
    int rob(TreeNode* root) {
        pair<int, int> p = help(root);
        return max(p.first, p.second);
    }
};