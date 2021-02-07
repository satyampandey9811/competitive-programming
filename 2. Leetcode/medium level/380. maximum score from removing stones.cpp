// link to question - https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> d = {a, b, c};
        sort(d.begin(), d.end());
        if(d[0] + d[1] <= d[2]) return d[0] + d[1];        
        return (a + b + c) / 2;
    }
};