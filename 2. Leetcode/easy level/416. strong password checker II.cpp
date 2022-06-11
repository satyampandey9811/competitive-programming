// link to question - https://leetcode.com/problems/strong-password-checker-ii/

class Solution {
public:
    bool strongPasswordCheckerII(string a) {
        set<char> st = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        int n = a.size();

        if (n < 8) return 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) return 0;
        }
        
        bool z = false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] >= 'A' and a[i] <= 'Z') {
                z = true;
                break;
            }
        }
        
        if (!z) return 0;
        z = false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] >= '0' and a[i] <= '9') {
                z = true;
                break;
            }
        }
        
        if (!z) return 0;
        z = false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] >= 'a' and a[i] <= 'z') {
                z = true;
                break;
            }
        }
        
        if (!z) return 0;
        z = false;
        
        for (int i = 0; i < n; i++) {
            if (st.count(a[i])) {
                z = true;
                break;
            }
        }
        
        return z;
    }
};