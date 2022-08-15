// link to question - https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
public:
    set<string> st;
    int n;
    
    void find (int prev, int ind, vector<int>& b, string& a) {
        if (ind == n) {
            string s;
            for (auto &i :b) {
                s += to_string(i);
            }
            st.insert(s);
            return;
        }
        
        for (int i = 1; i < 10; i++) {
            if (a[ind] == 'D') {
                if (prev <= i) continue;
            }
            else {
                if (prev >= i) continue;
            }
            
            bool g = true;
            for (int j = 0; j < b.size(); j++) {
                if (b[j] == i) {
                    g = false;
                    break;
                }
            }
            if (!g) continue;
            
            b.push_back(i);
            find (i, ind + 1, b, a);
            b.pop_back();
        }
    }
    
    string smallestNumber(string a) {
        n = a.size();
        vector<int> b;
        
        for (int i = 1; i < 10; i++) {
            b.push_back(i);
            find (i, 0, b, a);
            b.pop_back();
        }
        
        return *st.begin();
    }
};