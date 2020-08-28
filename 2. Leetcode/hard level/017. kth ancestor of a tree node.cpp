// link to question - https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
public:    
    int store[50002][20];
    int max;
    
    void fill(int x, int y) {
        store[x][0] = y;
        for(int i = 1; i <= max; i++) {
            store[x][i] = store[store[x][i-1]][i-1];
            if(store[x][i] == -1)
                return;
        }
    }
    
    TreeAncestor(int n, vector<int>& parent) {
        memset(store, -1, sizeof store);
        max = (int)ceil(log2(n));
        for(int i = 1; i < parent.size(); i++) {
            fill(i, parent[i]);            
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i <= max; i++) {
            if(k & (1 << i)) {
                node = store[node][i];
                if(node == -1)
                    return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */