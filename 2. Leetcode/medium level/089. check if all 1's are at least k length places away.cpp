// link to question - https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

class Solution {
public:
    bool kLengthApart(vector<int>& a, int k) {
        int pos = -1;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 1) {
                if(pos != -1 and i - pos - 1 < k)
                    return false;
                pos = i;
            }
        }
        return true;
    }
};