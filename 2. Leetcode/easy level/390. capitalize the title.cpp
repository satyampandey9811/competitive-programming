// link to question - https://leetcode.com/problems/capitalize-the-title/

class Solution {
public:
    string capitalizeTitle(string a) {
        int len = a.size();
        
        for (int i = 0; i < len; i++) {
            int j = i;
            
            while (j < len and a[j] != ' ') {
                j++;
            }
            
            if (j - i > 2) {
                a[i] = toupper(a[i]);
                i++;
                while (i < len and a[i] != ' ') {
                    a[i] = tolower(a[i]);
                    i++;
                }
            }
            
            else {
                while (i < len and a[i] != ' ') {
                    a[i] = tolower(a[i]);
                    i++;
                }
            }
            
            i = j;
        }
        
        return a;
    }
};