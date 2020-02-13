// link to question - https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size(), x;
        for(int i = 0; i < n; i++){
            x = a[i] % n;
            a[x] += n;
        }
        for(int i = 0; i < n; i++){
            a[i] /= n;
            if(a[i] > 1)
                return i;
        }
        return 0;
    }
};