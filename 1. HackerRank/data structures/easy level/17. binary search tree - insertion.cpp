// link to question - https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem



/*
Node is defined as 

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

    Node * insert(Node * root, int data) {
        if(root==NULL){
            Node* temp=(Node *)malloc(sizeof(Node));
            temp->data=data;
            return temp;
        }
        if(data<=root->data)
            root->left= insert(root->left,data);
        else 
            root->right= insert(root->right,data);
        return root;
    }

