// link to question - https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
    bool checkIfExist(vector<int>& a) {
        sort(a.begin(), a.end());
        for(int i = 0; i < a.size() - 1; i++){
            for(int j = i + 1; j < a.size(); j++){
                if(a[j] == 2 * a[i] or a[i] == 2 * a[j])
                    return true;
            }
        }
        return false;
    }
};