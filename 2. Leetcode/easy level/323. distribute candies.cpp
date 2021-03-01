// link to question - https://leetcode.com/problems/distribute-candies/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> m;
        int n = candyType.size();
        for(int &i : candyType) {
            m[i]++;
        }
        
        return min((int)m.size(), n / 2);
    }
};¡