// link to question - https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s, string t) {
        vector<int> a(26), b(26);
        for(auto i: s) {
            a[i - 'a']++;
        }
        int c = 0, n = s.size(), j = 0;
        for(int i = 0; i < t.size(); i++) {
            c++;
            b[t[i] - 'a']++;
            if(c == n) {
                bool flag = true;
                for(int j = 0; j < 26; j++) {
                    if(a[j] != b[j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) 
                    return 1;
                b[t[j] - 'a']--;
                c--;
                j++;
            }
        }
        return 0;
    }
};