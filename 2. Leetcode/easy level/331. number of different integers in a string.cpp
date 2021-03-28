// link to question - https://leetcode.com/problems/number-of-different-integers-in-a-string/

class Solution {
public:
    int numDifferentIntegers(string a) {
        set<string> s;
        int n = a.size();
        
        for(int i = 0; i < n; i++) {
            if(a[i] == '0') {
                if(i + 1 == n) s.insert("0");
                else if(a[i+1] >= 'a' and a[i+1] <= 'z') s.insert("0");
            }
            if(a[i] >= '1' and a[i] <= '9') {
                string t;
                t += a[i];
                int j = i + 1;
                while(j < n and a[j] >= '0' and a[j] <= '9') t += a[j++];
                s.insert(t);
                i = j;
            }
        }
        
        return (int)s.size();
    }
};