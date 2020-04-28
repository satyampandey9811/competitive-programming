// link to question - https://leetcode.com/problems/first-unique-number/

class FirstUnique {    
    unordered_map<int, int> m;
    queue<int> q;
    
public:
    FirstUnique(vector<int>& nums) {
        int x;
        for(int i = 0; i < nums.size(); i++){
            x = nums[i];
            m[x]++;
            q.push(x);
        }        
    }
    
    int showFirstUnique() {
        while(!q.empty()){
            if(m[q.front()] == 1)
                return q.front();
            q.pop();
        }
        return -1;
    }
    
    void add(int value) {
        q.push(value);
        m[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */