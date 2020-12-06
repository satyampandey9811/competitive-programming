// link to question - https://leetcode.com/problems/max-number-of-k-sum-pairs/

class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        map<int, int> m;
        int ans = 0;
        int n = a.size();
        
        for(int i = 0; i < n; i++) {            
            if(m.count(k - a[i])) {
                ans++;
                m[k - a[i]]--;
                if(m[k-a[i]] == 0) m.erase(k - a[i]);
            }
            else m[a[i]]++;
        }
        
        return ans;
    }
};