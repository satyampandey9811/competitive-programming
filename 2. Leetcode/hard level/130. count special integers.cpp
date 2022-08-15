// link to question - https://leetcode.com/problems/count-special-integers/

class Solution {
public:
    int go (int num, int times) {
        int ans = 1;
        while (times) {
            ans *= num;
            num--;
            times--;
        }
        return ans;
    }
    
    int countSpecialNumbers(int n) {
        int num = n, dig = 0;
        while (num > 0) {
            dig++;
            num /= 10;
        }
        
        vector<int> a(11, 9);
        for (int i = 2; i < 11; i++) {
            a[i] = 11 - i;
            a[i] *= a[i - 1];
        }
        
        int ans = 0;
        for (int i = 1; i < dig; i++) ans += a[i];
        
        set<int> st;
        string s = to_string(n);
        int len = s.size();
        int v, y;
        bool f = true;
        
        for (int i = 0; i < len; i++) {
            v = s[i] - '0';
            y = v;
            if (i == 0) y--;
            for (int j = 0; j < v; j++) {
                if (st.count(j)) y--;
            }
            
            ans += y * go (9 - i, len - i - 1);
            
            if (st.count(v)) {
                f = false;
                break;
            }
            st.insert(v);
        }
        
        if (f) ans++;
        
        return ans;
    }
};