// link to question - https://leetcode.com/problems/strictly-palindromic-number/

class Solution {
public:
    bool go (int n, int b) {
        string a;
        while (n > 1) {
            if (n % b == 0) a += '0';
            else a += to_string(n % b);
            n /= b;
        }
        a += '1';
        cout << a << endl;
        int i = 0, j = a.size() - 1;
        while (i < j) {
            if (a[i] != a[j]) return 0;
            i++, j--;
        }
        return 1;
    }
    
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i < n - 1; i++) {
            if (!go (n, i)) return 0;
        }
        return 1;
    }
};