// link to question - https://leetcode.com/problems/binary-tree-cameras/

class Solution {
public:
    int ans;
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        
        if(left == 1 or right == 1) {
            ans++;
            return -1;
        }
        return min(left, right) + 1;
    }
    
    int minCameraCover(TreeNode* root) {                
        ans = 0;
        if(dfs(root) == 1) ans++;
        return ans;
    }
};