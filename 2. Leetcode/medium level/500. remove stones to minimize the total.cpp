// link to question - https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        make_heap(a.begin(), a.end());
        int val;
        
        while(k > 0) {
            val = a.front();
            pop_heap(a.begin(), a.end());
            a.pop_back();
            a.push_back(val - val / 2);
            push_heap(a.begin(), a.end());
            k--;
        }
        
        int ans = 0;
        sort_heap(a.begin(), a.end());
        for(int i = 0; i < (int)a.size(); i++) {
            ans += a[i];
        }
        return ans;
    }
};