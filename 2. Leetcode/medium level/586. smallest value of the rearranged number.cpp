// link to question - https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        
        long long ans = 0;
        if (num >= 0) {
            vector<int> a;
            int z = 0;
            while (num) {
                a.push_back(num % 10);
                if (num % 10 == 0) z++;
                num /= 10;
            }
            sort(a.begin(), a.end());
            
            int i = 0;
            while (a[i] == 0) i++;
            ans = a[i++];
            for (int j = 0; j < z; j++) {
                ans = ans * 1LL * 10;
            }
            int n = a.size();
            while (i < n) {
                ans = ans * 1LL * 10 + a[i];
                i++;
            }
        }
        else {
            vector<int> a;
            num *= -1;
            while (num) {
                a.push_back(num % 10);
                num /= 10;
            }
            sort(a.rbegin(), a.rend());
            for (auto &i :a) {
                ans = ans * 1LL * 10 + i;
            }
            ans = ans * 1LL * (-1);
        }
        
        return ans;
    }
};