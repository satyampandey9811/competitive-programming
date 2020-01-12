// link to question - https://leetcode.com/problems/maximum-of-absolute-value-expression/submissions/

class Solution {
public:
    int cal(vector<int> a){
        return *max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
    }
    
    int maxAbsValExpr(vector<int>& a1, vector<int>& a2) {
        int n=a1.size();
        vector<int> exp1(n), exp2(n), exp3(n), exp4(n);
        for(int i=0;i<n;i++){
            exp1[i]=a1[i]+a2[i]+i;
            exp2[i]=a1[i]+a2[i]-i;
            exp3[i]=a1[i]-a2[i]+i;
            exp4[i]=a1[i]-a2[i]-i;
        }    
        return max( max(cal(exp1), cal(exp2)), 
                    max(cal(exp3), cal(exp4)));
    }
};