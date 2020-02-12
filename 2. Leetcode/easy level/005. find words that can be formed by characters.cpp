// link to question - https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class Solution {
public:
    int countCharacters(vector<string>& a, string c) {
        int n=a.size();
        int sum=0;
        for(int i=0;i<n;i++){
            string b=c;
            int d=0;
            for(int j=0;j<a[i].size();j++){
                auto it=find(b.begin(),b.end(),a[i][j]);
                if(it==b.end()){
                    d=0;break;
                }
                d=1;
                *it='1';
            }
            if(d){
                sum+=a[i].size();
            }
        }
        return sum;
    }
};