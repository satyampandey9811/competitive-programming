// link to question - https://leetcode.com/problems/positions-of-large-groups/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<int> p;int c=0;
        vector<vector<int>> a;
        int i,j=0;
        for(i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                c++;p.push_back(i);
            }
            else if(c>=2 and s[i]!=s[i+1]){
                p.push_back(i);
                a.push_back(vector<int>(2));
                a[j][0]=p[0];a[j][1]=p[p.size()-1];
                j++;p={};c=0;
            }
            else if(s[i]!=s[i+1]){
                p={};c=0;
            }
        }
        if(c>=2){
            p.push_back(i);
            a.push_back(vector<int>(2));
            a[j][0]=p[0];a[j][1]=p[p.size()-1];
        }
        return a;
    }
};