// link to question - https://leetcode.com/problems/find-the-k-beauty-of-a-number/

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string a = to_string(num);
        int n = a.size();
        
        for (int i = 0; i <= n - k; i++) {
            string b = a.substr(i, k);
            int nn = stoi(b);
            if (nn > 0 and num % nn == 0) ans++;
        }
        
        return ans;
    }
};