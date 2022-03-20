// link to question - https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

class Solution {
public:
    int countHillValley(vector<int>& a) {
        int n = a.size(), ans = 0;
        int j, k;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] == a[i - 1]) continue;
            j = i - 1;
            k = i + 1;
            while (j >= 0 and a[j] == a[i]) j--;
            while (k < n and a[k] == a[i]) k++;
            if (j >= 0 and k < n) {
                if (a[j] < a[i] and a[i] > a[k]) ans++;
                else if (a[j] > a[i] and a[i] < a[k]) ans++;
            }
        }
        return ans;
    }
};