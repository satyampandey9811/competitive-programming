// link to question - https://leetcode.com/problems/reveal-cards-in-increasing-order/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& a) {
        deque<int> ans;
        sort(a.begin(), a.end());
        
        ans.push_back(a.back());
        for(int i = a.size() - 2; i >= 0; i--) {
            int x = ans.back();
            ans.pop_back();
            ans.push_front(x);
            ans.push_front(a[i]);
        }
        
        vector<int> res;
        for(auto i: ans) res.push_back(i);
        return res;
    }
};