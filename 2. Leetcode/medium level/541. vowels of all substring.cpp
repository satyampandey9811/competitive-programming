// link to question - https://leetcode.com/problems/vowels-of-all-substrings/

class Solution {
public:
    long long countVowels(string a) {
        int n = a.size();
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] == 'a' or a[i] == 'e' or a[i] == 'i' or a[i] == 'o' or a[i] == 'u') {
                ans += (i + 1) * 1LL * (n - i);
            }
        }
        
        return ans;
    }
};