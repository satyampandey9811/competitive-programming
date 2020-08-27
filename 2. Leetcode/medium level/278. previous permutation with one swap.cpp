// link to question - https://leetcode.com/problems/previous-permutation-with-one-swap/

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        int n = a.size();        
        
        set<int> s;
        map<int, int> m;
        int minval = a.back();                
        
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] > minval) {
                auto it = s.lower_bound(a[i]);
                it--;
                int x = a[i];
                a[i] = *it;
                a[m[*it]] = x;
                return a;
            }
            minval = a[i];
            s.insert(a[i]);
            m[a[i]] = i;
        }
        
        return a;
    }
};