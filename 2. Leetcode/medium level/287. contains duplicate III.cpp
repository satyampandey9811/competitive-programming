// link to question - https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        int n = a.size(), j = 0;        
        multiset<int> m;        
        long long int diff;
        
        for(int i = 0; i < n; i++) {            
            if(m.size() <= k) {
                auto it = m.lower_bound(a[i]);
                if(it != m.end()) {
                    diff = *it;
                    diff -= a[i];
                    if(diff <= t) return 1;
                }
                if(it != m.begin()) {
                    it--;
                    diff = a[i];
                    diff -= *it;
                    if(diff <= t) return 1;
                }
                
                if(m.size() == k) {
                    auto it2 = m.find(a[j]);
                    if(it2 != m.end()) m.erase(it2);
                    j++;    
                }
                
                m.insert(a[i]);
            } 
            else m.insert(a[i]);
        }
        
        return 0;
    }
};