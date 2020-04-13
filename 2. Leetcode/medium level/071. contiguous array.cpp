// link to question - https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int ans = 0, n = a.size(), sum = 0;
        map<int, int> m;
        m[0] = -1;
        
        for(int i = 0; i < n; i++){
            if(a[i] == 0) a[i] = -1;
        }
        
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(m.find(sum) != m.end())
                ans = max(ans, i - m[sum]);
            else
                m[sum] = i;
        }
        
        return ans;
    }
};