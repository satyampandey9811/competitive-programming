// link to question - https://leetcode.com/problems/bulb-switcher-iii/

class Solution {
public:
    int numTimesAllBlue(vector<int>& a) {
        int ans = 0, n = a.size();
        vector<int> s(n);
        int maxnum = 0, j = 0;
        for(int i = 0; i < n; i++){
            maxnum = max(maxnum, a[i]);
            s[a[i] - 1] = 1;
            bool flag = true;            
            for(; j < maxnum; j++){
                if(s[j] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                j = maxnum;
                ans++;
            }
        }
        return ans;
    }
};