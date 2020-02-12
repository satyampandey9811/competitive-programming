// link to question - https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        
        vector<int> b,c;
        for(int i=0;i<a2.size();i++){
            for(int j=0;j<a1.size();j++){
                if(a2[i]==a1[j]){
                    b.push_back(a1[j]);
                }
            }
        }
        for(int i=0;i<a1.size();i++){
            auto it=find(a2.begin(),a2.end(),a1[i]);
            if(it==a2.end()){
                c.push_back(a1[i]);
            }
        }
        sort(c.begin(),c.end());
        for(int i=0;i<c.size();i++){
            b.push_back(c[i]);
        }
        return b;
    }
};