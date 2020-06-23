// link to question - https://leetcode.com/problems/valid-square/

class Solution {
public:
    double sum(vector<int> a , vector<int> b){
        return fabs(a[0]-b[0])+fabs(a[1]-b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> x;    
        x.push_back(sum(p1,p2));
        x.push_back(sum(p1,p3));
        x.push_back(sum(p1,p4));
        x.push_back(sum(p2,p3));
        x.push_back(sum(p2,p4));
        x.push_back(sum(p3,p4));

        int m=accumulate(x.begin(),x.end(),0);
        if(m==0)
            return false;
        sort(x.begin(),x.end());
        if((x[0]==x[1] and x[0]==x[2]) and x[0]==x[3])
            return true;
        else
            return false;
    }
};