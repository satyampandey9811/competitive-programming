// link to question: https://leetcode.com/problems/array-of-doubled-pairs/

class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        int n = a.size();
        if(n == 0) return 1;
        
        sort(a.begin(), a.end());
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) m[a[i]]++;
        
        int i = 0;
        while(i < n and a[i] < 0) i++;
        
        int j = i;
        while(j < n) {
            if(m[a[j]] < 1) {
                j++;
                continue;
            }
            if(j + 1 >= n) return 0;
            if(m[2 * a[j]] < 1) return 0;
            m[a[j]]--;
            m[2 * a[j]]--;
            j++;
        }
        
        i--;
        while(i > 0) {
            if(m[a[i]] < 1) {
                i--;
                continue;
            }
            if(i - 1 < 0) return 0;
            if(m[2 * a[i]] < 1) return 0;
            m[a[i]]--;
            m[2 * a[i]]--;
            i--;
        }
        return 1;
    }
};