// link to question - https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size(), x;
        for(int i = 0; i < n; i++){
            if(a[i] > n or a[i] < 0)
                a[i] = 0;
        }
        for(int i = 0; i < n; i++){
            x = a[i] % (n + 1);
            if(x == 0) continue;
            a[x - 1] += n + 1;
        }        
        for(int i = 0; i < n; i++){
            if(a[i] / (n + 1) == 0)
                return i + 1;
        }
        return n + 1;
    }
};