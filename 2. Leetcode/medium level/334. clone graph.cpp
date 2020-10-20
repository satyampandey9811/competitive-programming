// link to question - https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:        
    unordered_map<Node*, Node*> m;
    
    Node* go(Node* node) {
        if(m.count(node)) return m[node];
        m[node] = new Node(node -> val);        
        for(auto i: node -> neighbors) {
            m[node] -> neighbors.push_back(go(i));
        }
        return m[node];
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return go(node);        
    }
};