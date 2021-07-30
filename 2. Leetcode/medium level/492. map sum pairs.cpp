// link to question - https://leetcode.com/problems/map-sum-pairs/

class MapSum {
public:
    unordered_map<string, int> m;
    unordered_map<string, int> s;
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int n = key.size();
        if(s.count(key) < 1) {
            s[key] = val;
            for(int i = 0; i < n; i++) {
                m[key.substr(0, i + 1)] += val;
            }
        }
        else {
            int sub = s[key];
            for(int i = 0; i < n; i++) {
                m[key.substr(0, i + 1)] += (val - sub);
            }
            s[key] = val;
        }
    }
    
    int sum(string prefix) {
        return m[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */