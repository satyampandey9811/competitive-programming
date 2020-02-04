// link to question - https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string a) {
        int n = a.size();
        unordered_map<char, int> m;
        for(int i = 0; i < n; i++)
            m[a[i]]++; 
        for(int i = 0; i < n; i++){            
            if(m[a[i]] == 1)
                return i;
        }
        return -1;
    }
};