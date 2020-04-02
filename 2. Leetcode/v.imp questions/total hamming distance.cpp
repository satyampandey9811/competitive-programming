// link to question - https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        for(int i = 0; i < 32; i++){
            int bitone = 0;
            for(auto x: nums){
                if(x & (1 << i))
                    bitone++;
            }
            ans += bitone * (n - bitone);
        }
        return ans;
    }
};