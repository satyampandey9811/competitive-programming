// link to question - https://leetcode.com/problems/insert-into-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {        
        TreeNode *temp = root, *newnode = new TreeNode(val);
        
        while(true){
            if(val < temp -> val){
                if(temp -> left)
                    temp = temp -> left;
                else{
                    temp -> left = newnode;
                    break;
                }
            }
            else{
                if(temp -> right)
                    temp = temp -> right;
                else{
                    temp -> right = newnode;
                    break;
                }
            }
        }
        return root ?root :newnode ;
    }
};