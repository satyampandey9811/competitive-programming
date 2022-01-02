// link to question - https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        long long m = mass;
        sort(a.begin(), a.end());
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (m < (long long)a[i]) return false;
            m += a[i];
        }
        return true;
    }
};