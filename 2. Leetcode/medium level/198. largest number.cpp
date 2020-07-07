// link to question - https://leetcode.com/problems/largest-number/

bool comp(const int& x, const int& y) {
    string a = to_string(x), b = to_string(y);
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& a) {        
        sort(a.begin(), a.end(), comp);
        string ans;
        for(auto i: a) ans += to_string(i);        
        return ans[0] == '0' ? "0" : ans;
    }
};