// link to question - https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& a) {
        if(a.size()==0) return m*n;
        int first=40001,second=40001;
        for(int i=0;i<a.size();i++){
            if(a[i][0]<first)
                first=a[i][0];
            if(a[i][1]<second)
                second=a[i][1];
        }
        return first*second;
    }
};