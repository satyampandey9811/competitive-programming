// link to question - https://leetcode.com/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n = a.size();
        vector<int> maxFromLeft(a.begin(), a.end());
        vector<int> minFromRight(a.begin(), a.end());
        
        for(int i = 1; i < n; i++) {
            maxFromLeft[i] = max(maxFromLeft[i], maxFromLeft[i-1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            minFromRight[i] = min(minFromRight[i], minFromRight[i+1]);
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(maxFromLeft[i] <= minFromRight[i + 1]) return i + 1;
        }
        return 0;
    }
};