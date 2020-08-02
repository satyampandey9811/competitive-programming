// link to question - https://leetcode.com/problems/find-the-winner-of-an-array-game/

class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        int n = a.size();
        for(int i = 0; i < n;) {
            int j = i + 1, c = 0;
            while(j < n and a[i] > a[j]) c++, j++;
            if(i > 0) c++;
            if(c >= k) return a[i];
            i = j;
        }
        return *max_element(a.begin(), a.end());
    }
};