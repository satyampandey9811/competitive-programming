// link to question - https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

class Solution {
public:
    bool canBeIncreasing(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            vector<int> b;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                b.push_back(a[j]);
            }
            bool f = true;
            for(int j = 0; j < n - 2; j++) {
                if(b[j] >= b[j+1]) {
                    f = false;
                    break;
                }
            }
            if(f) return 1;
        }
        return 0;
    }
};