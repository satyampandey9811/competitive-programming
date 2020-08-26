// link to question - https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

class Solution {
public:
    vector<int> res;
    int i;
    
    bool dfs(TreeNode* root, vector<int>& voyage) {
        if(!root) return 1;
        
        if(!root -> left and !root -> right) return 1;
        
        if(root -> left and !root -> right) {
            if(root -> left -> val != voyage[i]) return 0;
            i++;
            return dfs(root -> left, voyage);
        }
        
        if(!root -> left and root -> right) {
            if(root -> right -> val != voyage[i]) return 0;
            i++;
            return dfs(root -> right, voyage);
        }
        
        bool ans = false;
        if(root -> left -> val == voyage[i]) {
            i++;
            ans = dfs(root -> left, voyage);
        }
        else if(root -> right -> val == voyage[i]) {
            res.push_back(root -> val);
            swap(root -> left, root -> right);
            i++;
            ans = dfs(root -> left, voyage);
        }
        if(!ans) return 0;
        
        if(root -> right -> val != voyage[i]) return 0;        
        i++;
        return dfs(root -> right, voyage);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(root -> val != voyage[0]) return {-1};
        i = 1;
        if(!dfs(root, voyage)) return {-1};
        return res;
    }
};