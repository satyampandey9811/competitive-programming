// link to question - https://leetcode.com/problems/k-divisible-elements-subarrays/

class Solution {
public:
    int countDistinct(vector<int>& a, int k, int p) {
        int n = a.size();
        int ans = 0;
//         vector<int> b;
//         for (int i = 0; i < n; i++) {
//             if (a[i] % p == 0) b.push_back(i);
//         }
        
//         b.push_back(n);
//         int len = b.size();
//         int j = 0;
        
//         set<vector<int>> s;
        
//         for (int i = 0; i < n; i++) {
//             if (i > b[j]) j++;
            
//             int r = min(len - 1, j + k);
//             ans += b[r] - i;
//             cout << b[r] - i << ' ';
//         }
//         cout << endl;
        
        set<vector<int>> s;
        
        for (int i = 0; i < n; i++) {
            int c = 0;
            vector<int> temp;
            
            for (int j = i; j < n; j++) {
                if (a[j] % p == 0) c++;
                if (c > k) break;
                temp.push_back(a[j]);
                if (s.count(temp) < 1) {
                    s.insert(temp);
                    ans++;
                }
            }
            
            temp = {};
        }
        return ans;
    }
};