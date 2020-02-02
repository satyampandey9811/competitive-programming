// link to question - https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        unordered_set<int> us;
        for(auto i : a){
            if(us.count(i))
                return i;
            us.insert(i);
        }
        return 0;
    }
};