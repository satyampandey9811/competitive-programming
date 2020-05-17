// link to question - https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> a(26), b(26), ans;
        for(int i = 0; i < p.size(); i++) {
            b[p[i] - 'a']++;
        }
        int c = 0, n = p.size(), j = 0;
        for(int i = 0; i < s.size(); i++) {
            c++;
            a[s[i] - 'a']++;
            if(c == n) {
                bool flag = true;                
                for(int k = 0; k < 26; k++) {
                    //cout << a[k] << b[k] << endl;
                    if(a[k] != b[k]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans.push_back(j);
                a[s[j] - 'a']--;
                j++;
                c--;
            }
        }
        return ans;
    }
};