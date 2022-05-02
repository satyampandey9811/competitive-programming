// link to question - https://leetcode.com/problems/total-appeal-of-a-string/

class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<int> m(26, -1);
        long long ans = 0;
        int len;
        
        deque<array<int, 2>> temp;
        temp.push_back({-1, -1});
        int v;
        
        for (int i = 0; i < n; i++) {
            v = s[i] - 'a';
            if (m[v] == -1) temp.push_front({i, v});
            else {
                for (int j = temp.size() - 1; j >= 0; j--) {
                    if (temp[j][1] == v) {
                        temp[j][0] = i;
                        
                        for (int k = j; k > 0; k--) {
                            swap(temp[k], temp[k - 1]);
                        }
                        break;
                    }
                }
            }
            m[v] = i;
            
            len = temp.size();
            for (int j = 0; j < len - 1; j++) {
                ans += (temp[j][0] - temp[j + 1][0]) * (j + 1);
            }
        }
        
        return ans;
    }
};