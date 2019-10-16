// link to question - https://www.hackerrank.com/challenges/tree-level-order-traversal/problem


/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        if(root == NULL) return;
        queue<Node*> Q;
        Q.push(root);  
        
        while(!Q.empty()) {
            Node* current = Q.front();
            Q.pop(); 
            cout<<current->data<<" ";
            if(current->left != NULL) Q.push(current->left);
            if(current->right != NULL) Q.push(current->right);
        }

    }

