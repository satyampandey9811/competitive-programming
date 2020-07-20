// link to question - https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution {
public:
    vector<int> dfs(int id, int parent, vector<vector<int>>& tree, vector<int>& output, string &labels){
        vector<int> temp(26);
        
        for(auto x: tree[id]){
            if(x == parent) continue;
            
            vector<int> val = dfs(x, id, tree, output, labels);
            for(int i = 0; i < 26; i++) temp[i] += val[i];
        }
        temp[labels[id] - 'a']++;
        
        output[id] = temp[labels[id] - 'a'];
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels){
        ios::sync_with_stdio(false), cin.tie(0);
        vector<vector<int>> tree(n);
        for(auto edge : edges){
            int x = edge[0], y = edge[1];
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        
        vector<int> output(n);
        dfs(0, -1, tree, output, labels);
        return output;
    }
};