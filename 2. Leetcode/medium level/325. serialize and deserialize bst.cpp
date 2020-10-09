// link to question - https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string ans;
    void go(TreeNode* root) {
        if(!root) return;
        int x = 14, n = root -> val;
        while(x) {
            ans += to_string(n % 2);
            n /= 2;
            x--;
        }
        go(root -> left);
        go(root -> right);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans = "";
        go(root);
        return ans;
    }
    
    TreeNode* help(TreeNode* root, int num) {
        if(!root) root = new TreeNode(num);                        
        else if(num <= root -> val) root -> left = help(root -> left, num);
        else root -> right = help(root -> right, num);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0, n = data.size();
        TreeNode* root = NULL;        
        for(int i = 0; i < n; i += 14) {
            int num = 0;
            for(int j = i; j < i + 14; j++) {
                if(data[j] == '1') num += pow(2, j - i);                
            }
            root = help(root, num);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;