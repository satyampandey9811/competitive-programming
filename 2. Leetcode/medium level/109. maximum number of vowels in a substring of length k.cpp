// link to question - https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string a, int k) {
        int n = a.size();
        int ans = 0, c = 0, v = 0, j = 0;
        
        for(int i = 0; i < n; i++) {
            c++;
            if(a[i] == 'a' or a[i] == 'e' or a[i] == 'i' or a[i] == 'o' or a[i] == 'u') {
                v++;
            }
            ans = max(ans, v);
            if(c == k) {
                if(a[j] == 'a' or a[j] == 'e' or a[j] == 'i' or a[j] == 'o' or a[j] == 'u')
                    v--;
                j++;
                c--;
            }
        }
        
        return ans;
    }
};