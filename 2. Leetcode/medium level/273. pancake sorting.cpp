// link to question - https://leetcode.com/problems/pancake-sorting/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        int c = n;
        
        for(int i = 1; i < n; i++) {
            int m = max_element(a.begin(), a.begin() + c) - a.begin();
            if(m == 0) {
                ans.push_back(c);
                reverse(a.begin(), a.begin() + c);
            }
            else if(m != c - 1) {
                ans.push_back(m + 1);
                reverse(a.begin(), a.begin() + m + 1);
                ans.push_back(c);
                reverse(a.begin(), a.begin() + c);
            }
            c--;
        }
        
        return ans;
    }
};