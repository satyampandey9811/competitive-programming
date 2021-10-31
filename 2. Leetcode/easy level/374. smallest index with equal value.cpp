// link to question - https://leetcode.com/problems/smallest-index-with-equal-value/

class Solution {
public:
    int smallestEqual(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(i % 10 == a[i]) return i;
        }
        return -1;
    }
};