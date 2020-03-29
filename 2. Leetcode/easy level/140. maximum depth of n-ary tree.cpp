// link to question - https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
#include<bits/stdc++.h>
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        int ans = 0;
        for(int i = 0; i < root -> children.size(); i++){
            int x = maxDepth(root -> children[i]);
            ans = max(ans, x);
        }
        return 1 + ans;
    }
};