// link to question - https://leetcode.com/problems/number-of-recent-calls/

class RecentCounter {      
public:
    vector <int> calls;
    int l = 0, r = 0;
    
    RecentCounter() { 
        calls.resize(10000);
    }
    
    int ping(int t) {
        calls[r++] = t;
        
        while (calls[l] < t - 3000)
            ++l;
        
        return r - l;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */