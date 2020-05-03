// link to question - https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& a, int l) {
        int i, j = 0;
        multiset<int> m;                    
        
        for(i = 0; i < a.size(); i++) {
            m.insert(a[i]);                          
            if(*m.rbegin() - *m.begin() > l) {
                m.erase(m.find(a[j]));                
                j++;
            }                        
        }
        return i - j;
    }
};