// link to question - https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        set<int> s(a.begin(), a.end());
        int c = 0, ans;        
        for(int i = 1; i <= 2009; i++) {
            if(s.count(i) == 0) c++;
            if(c == k) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};