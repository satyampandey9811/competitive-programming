// link to question - https://leetcode.com/problems/finding-3-digit-even-numbers/

class Solution {
public:
    set<int> s;
    vector<int> d;
    
    void go(int &a, int &b, int &c) {
        d[0] = a, d[1] = b, d[2] = c;
        do {
            if (d[0] == 0) continue;
            if (d[2] & 1) continue;
            s.insert(d[0] * 100 + d[1] * 10 + d[2]);
            
        } while (next_permutation(d.begin(), d.end()));
    }
    
    vector<int> findEvenNumbers(vector<int>& a) {
        vector<int> ans;
        d = vector<int>(3);
        sort(a.begin(), a.end());
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    go(a[i], a[j], a[k]);
                }
            }
        }
        for (auto &i :s) ans.push_back(i);
        return ans;
    }
};