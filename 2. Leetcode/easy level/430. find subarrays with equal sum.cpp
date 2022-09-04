// link to question - https://leetcode.com/problems/find-subarrays-with-equal-sum/

class Solution {
public:
    bool findSubarrays(vector<int>& a) {
        map<int, int> m;
        for (int i = 1; i < a.size(); i++) {
            m[a[i] + a[i - 1]]++;
            if (m[a[i] + a[i - 1]] > 1) return 1;
        }
        return 0;
    }
};