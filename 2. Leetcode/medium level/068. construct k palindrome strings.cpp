// link to question - https://leetcode.com/problems/construct-k-palindrome-strings/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) 
            return false;
        
        vector<int> a(26);
        for(auto i: s)
            a[i - 'a']++;
        
        int oddcount = 0;
        for(auto i: a){
            if(i & 1)
                oddcount++;
        }
        
        if(oddcount > k) 
            return false;
        return true;
    }
};