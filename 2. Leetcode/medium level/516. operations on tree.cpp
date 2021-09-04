// link to question - https://leetcode.com/problems/operations-on-tree/

class LockingTree {
public:
    vector<vector<int>> des;
    vector<int> par;
    int n;
    int loc[2002];
    
    LockingTree(vector<int>& a) {
        n = a.size();
        for(int i = 0; i < n; i++) loc[i] = 0;
        des = vector<vector<int>>(n);
        for(int i = n - 1; i > 0; i--) {
            des[a[i]].push_back(i);
        }
        par = vector<int>(n);
        for(int i = 0; i < n; i++) par[i] = a[i];
    }
    
    bool lock(int num, int user) {
        if(loc[num] > 0) return 0;
        loc[num] = user;
        return 1;
    }
    
    bool unlock(int num, int user) {
        if(loc[num] == user) {
            loc[num] = 0;
            return 1;
        }
        return 0;
    }
    
    bool upgrade(int num, int user) {
        if(loc[num] > 0) return 0;
        int p = num;
        while(p != -1) {
            if(loc[p] > 0) return 0;
            p = par[p];
        }
        if(dfs(num)) {
            loc[num] = user;
            return 1;
        }
        return 0;
    }
    
    bool dfs(int i) {
        bool ans = false;
        if(loc[i] > 0) {
            ans = true;
            loc[i] = 0;
        }
        for(auto &j :des[i]) {
            if(dfs(j)) {
                ans = true;
            }
        }
        return ans;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */