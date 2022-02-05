// link to question - https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {
        int n = a.size();
        int j = 0;
        vector<int> b;
        
        for (int i = 0; i < n; i++) {
            if (a[i] < p) b.push_back(a[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] == p) b.push_back(a[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] > p) b.push_back(a[i]);
        }
        
        return b;
    }
};