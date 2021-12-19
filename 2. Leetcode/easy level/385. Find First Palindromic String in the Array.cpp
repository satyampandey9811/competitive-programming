// link to question - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class Solution {
public:
    string firstPalindrome(vector<string>& a) {
        int n = a.size();
        bool f;
        int j, k;
        
        for (int i = 0; i < n; i++) {
            j = 0, k = a[i].size() - 1;
            f = true;
            
            while (j < k) {
                if (a[i][j] != a[i][k]) {
                    f = false;
                    break;
                }
                j++;
                k--;
            }
            
            if (f == true) {
                return a[i];
            }
        }
        
        return "";
    }
};