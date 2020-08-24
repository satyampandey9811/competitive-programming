// link to question - https://leetcode.com/problems/find-latest-group-of-size-m/

class Solution {
public:
    int findLatestStep(vector<int>& a, int m) {
        int n = a.size();
        if(n == m) return n;        
        set<int> s = {0, n + 1};
        
        for(int i = n - 1; i > 0; i--) {                            
            auto it = s.upper_bound(a[i]);
            if(*it - a[i] - 1 == m) return i;
            it--;
            if(a[i] - *it - 1 == m) return i;
            s.insert(a[i]);
        }
        
        return -1;
    }
};