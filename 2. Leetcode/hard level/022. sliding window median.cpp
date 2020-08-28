// link to question - https://leetcode.com/problems/sliding-window-median/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        vector<double> ans;
        int n = a.size();
        
        multiset<int> section(a.begin(), a.begin() + k);
        auto mid = next(section.begin(), k / 2);    

        for(int i = k; ; i++) {        
            ans.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
            if(i == n) break;
            section.insert(a[i]);
            if(a[i] < *mid) mid--;
            if(a[i - k] <= *mid) mid++;
            section.erase(section.lower_bound(a[i - k]));
        }
        
        return ans;
    }
};