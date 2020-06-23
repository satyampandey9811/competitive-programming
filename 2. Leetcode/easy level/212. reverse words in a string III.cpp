// link to question - https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        vector<int> a;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')
                a.push_back(i-1);
        }
        a.push_back(s.size()-1);
        int p=0,q;
        for(int i=0;i<a.size();i++){
            q=a[i];
            reverse(s.begin()+p,s.begin()+q+1);
            p=a[i]+2;
        }
        return s;
    }
};