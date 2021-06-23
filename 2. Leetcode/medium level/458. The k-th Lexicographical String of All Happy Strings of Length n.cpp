// link to question - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
public:
    string getHappyString(int n, int k) {
        string s = "ababababab";
        string a = s.substr(0, n);
        
        for(int i = 0; i < k - 1; i++) {
            int j = n - 1;
            while(j > 0) {
                if(a[j] == 'b' and a[j-1] == 'a') {
                    a[j]++;
                    break;
                }
                else if(a[j] == 'a') {
                    a[j]++;
                    if(a[j-1] == 'b') a[j]++;
                    break;
                }
                j--;
            }
            if(j == 0 and a[j] == 'c') return "";
            if(j == 0) a[j]++;
            string t = a.substr(0, j + 1) + s.substr(0, n - j - 1);
            a = t;
        }
        
        return a;
    }
};