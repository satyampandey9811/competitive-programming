// link to question - https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        vector<int> ans;
        int n = a.size();
        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(j != i and a[j] < a[i])
                    c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};