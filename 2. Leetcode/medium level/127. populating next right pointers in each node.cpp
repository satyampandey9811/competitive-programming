// link to question - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void help(Node* root, int level, vector<Node*> &nxt) {
        if(root == NULL) return;
        if(nxt.size() < level) {
            root -> next = NULL;
            nxt.push_back(root);            
        }
        else {
            root -> next = nxt[level - 1];
            nxt[level - 1] = root;            
        }
        help(root -> right, level + 1, nxt);
        help(root -> left, level + 1, nxt);        
    }
    
    Node* connect(Node* root) {
        vector<Node*> nxt;
        help(root, 1, nxt);
        return root;
    }
};