// link to question - https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:    
    vector<int> postorder(Node* root) {
        if(root == NULL)
            return {};        
        vector<int> a;
        stack<Node*> s;
        s.push(root);
        
        while(s.size() != 0){
            Node* top = s.top();
            a.push_back(top -> val);
            s.pop();
            for(int i = 0; i < top -> children.size(); i++)
                s.push(top -> children[i]);
        }            
        reverse(a.begin(), a.end());
        return a;
    }
};