// link to question - https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string a) {      
        
        unordered_set s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(int i = 0, j = a.size() - 1; i < j;) {
            if(s.count(a[i]) > 0 and s.count(a[j]) > 0) {
                swap(a[i], a[j]);
                i++, j--;
            }
            else if(s.count(a[i]) > 0) j--;
            else if(s.count(a[j]) > 0) i++;
            else i++, j--;
        }        
        
        return a;
    }
};