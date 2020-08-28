// link to question - https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
public:    
    map<int, vector<int>> m;    
    vector<int> nums;
    
    RandomizedCollection() {
        
    }
        
    bool insert(int val) { 
        int ans = 0;
        if(m.count(val) == 0) ans = 1;
        nums.push_back(val);
        m[val].push_back(nums.size() - 1);        
        return ans;
    }
        
    bool remove(int val) {        
        if(m.count(val) > 0) {
            int last = nums.back();
            *m[last].rbegin() = m[val].back();
            nums[m[val].back()] = last;
            nums.pop_back();
            m[val].pop_back();
            if(m[val].size() == 0) m.erase(val);
            if(last != val)
                sort(m[last].begin(), m[last].end());
            return 1;
        }
        return 0;
    }
        
    int getRandom() {
        return nums[rand() % nums.size()];                                
    }
};