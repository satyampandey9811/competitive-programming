// link to question - https://leetcode.com/problems/design-a-number-container-system/

class NumberContainers {
public:
    unordered_map<int, int> m;
    unordered_map<int, set<int>> mp;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (m.count(index) > 0) {
            mp[m[index]].erase(index);            
        }
        m[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if (mp.count(number) < 1) return -1;
        if (mp[number].size() < 1) return -1;
        int ans = *mp[number].begin();
        return ans;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */