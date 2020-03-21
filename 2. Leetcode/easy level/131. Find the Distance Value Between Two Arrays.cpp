// link to question - https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int ans = 0;
        
        for(int i = 0; i < a.size(); i++){
            bool flag = true;
            for(int j = 0; j < b.size(); j++){
                if(abs(a[i] - b[j]) <= d){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};