// link to question - https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        if(a.size()==0)
            return "";
        string b="";int f=1;
        for(int i=0;i<a[0].size();i++){
            char c=a[0][i];
            for(int j=1;j<a.size();j++){
                if(c!=a[j][i]){
                    f=0;break;
                }
            }
            if(!f)
                break;
            b+=c;
        }
        return b;
    }
};