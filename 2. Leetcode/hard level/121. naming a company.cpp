// link to question - https://leetcode.com/problems/naming-a-company/

class Solution {
public:
    long long distinctNames(vector<string>& id) {
        long long ans = 0;
        unordered_map<string, int> m;
        
        for (auto &i :id) {
            m[i.substr(1)] |= (1 << (i[0] - 'a'));
        }
        
        int n = m.size(), x, y, c = 0;
        vector<int> a(n);
        
        for (auto &i :m) {
            a[c++] = i.second;
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                x = y = 0;
                for (int k = 0; k < n; k++) {
                    if ((1 & (a[k] >> i)) and (1 & (a[k] >> j))) continue;
                    if (1 & (a[k] >> i)) x++;
                    else if (1 & (a[k] >> j)) y++;
                }
                ans += x * 1LL * y;
            }
        }
        
        return ans * 2;
    }
};