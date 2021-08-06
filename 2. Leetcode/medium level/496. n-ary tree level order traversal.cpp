// link to question - https://leetcode.com/problems/n-ary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root) q.push(root);
        
        while(q.size()) {
            vector<int> temp;
            for(int i = q.size(); i > 0; i--) {
                auto front = q.front();
                q.pop();
                temp.push_back(front -> val);
                
                for(auto &j :front -> children) {
                    q.push(j);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};