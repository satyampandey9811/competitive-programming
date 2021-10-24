// link to question - https://leetcode.com/problems/number-of-valid-words-in-a-sentence/

class Solution {
public:
    bool check(int s, int e, string& a) {
        int h = 0;
        
        for(int i = s; i <= e; i++) {
            if(a[i] >= '0' and a[i] <= '9') return 0;
            if(a[i] == '-') {
                if(h == 1) return 0;
                if(i - 1 >= s and i + 1 <= e and a[i-1] >= 'a' and a[i-1] <= 'z' and a[i+1] >= 'a' and a[i+1] <= 'z') {
                    h = 1;
                    continue;
                }
                else return 0;
            }
            if((a[i] == '!' or a[i] == '.' or a[i] == ',') and i < e) {
                return 0;
            }
        }
        
        return 1;
    }
    
    int countValidWords(string a) {
        int n = a.size();
        int ans = 0;
        int s = -1, e;
        
        for(int i = 0; i < n; i++) {
            if(a[i] != ' ') {
                if(s == -1) {
                    s = i;
                }
                e = i;
            }
            else {
                if(s != -1 and check(s, e, a)) ans++;
                s = -1;
            }
        }
        if(a[n-1] != ' ') {
            if(check(s, e, a)) ans++;
        }
        
        return ans;
    }
};