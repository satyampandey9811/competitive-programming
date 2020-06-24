// link to question - https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string a) {
        string b;
        for(int i=0;i<a.size();i++){
            if(a[i]=='.'){
                b+="[.]";               
            }
            else
                b+=a[i];
        }
        return b;
    }
};