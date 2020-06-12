// link to question - https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> nums;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val) == 0) {
            nums.push_back(val);
            m[val] = nums.size() - 1;            
            return 1;
        }
        return 0;
    }
        
    bool remove(int val) {
        if(m.count(val) > 0) {
            int last = nums.back();
            m[last] = m[val];
            nums[m[val]] = last;
            nums.pop_back();
            m.erase(val);
            return 1;
        }
        return 0;
    }
        
    int getRandom() {
        return nums[rand() % nums.size()];                                
    }
};