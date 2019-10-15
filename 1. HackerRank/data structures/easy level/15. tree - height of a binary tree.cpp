// link to question - https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem


/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if(root==NULL) return -1;
        int a=height(root->left);
        int b=height(root->right);
        return max(a,b)+1;
    }

