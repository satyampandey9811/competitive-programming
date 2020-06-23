// link to question - https://leetcode.com/problems/implement-strstr/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if(n == 0)
            return 0;
        auto it = haystack.find(needle);
        if(it != haystack.size()) {
            return it;
        }                                    
        return -1;
    }
};