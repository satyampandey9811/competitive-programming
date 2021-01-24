// link to question - https://leetcode.com/problems/building-boxes/

class Solution {
public:
    int minimumBoxes(int n) {
        vector<int> a = {1};
        
        int i = 0;
        while(a[i] < n) {
            int j = i + 2;
            a.emplace_back(j * (j + 1) / 2 + a[i]);
            i++;
        }
        
        if(a[i] == n) {
            i++;
            return i * (i + 1) / 2;
        }
                
        if(a[i-1] + 1 == n) return i * (i + 1) / 2 + 1;        
        
        int val = a[i-1] + 1, ans = i * (i + 1) / 2 + 1;
        
        for(int j = 1; j <= i; j++) {
            val += j + 1;
            ans++;
            if(val >= n) return ans;
        }
        
        return ans;
    }
};