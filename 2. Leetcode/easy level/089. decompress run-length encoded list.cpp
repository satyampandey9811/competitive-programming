// link to question - https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& a) {
        vector<int> ans;
        int c;
        for(int i=0;i<a.size()-1;i=i+2){
            c=0;
            while(c<a[i]){
                ans.push_back(a[i+1]);
                c++;
            }
        }
        return ans;
    }
};