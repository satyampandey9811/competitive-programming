// link to question - https://leetcode.com/problems/largest-time-for-given-digits/

class Solution {
public:
    bool check(vector<int> &a) {
        if(a[0] > 2) return 0;
        if(a[0] == 2 and a[1] > 3) return 0;
        if(a[2] > 5) return 0;
        return 1;
    }
    
    string largestTimeFromDigits(vector<int>& a) {
        string ans;
        
        sort(a.begin(), a.end(), greater<int>());
        
        do {            
            if(check(a)) {
                ans += to_string(a[0]);
                ans += to_string(a[1]);
                ans += ':';
                ans += to_string(a[2]);
                ans += to_string(a[3]);
                return ans;
            }
            
        }while(prev_permutation(a.begin(), a.end()));
        
        return ans;
    }
};