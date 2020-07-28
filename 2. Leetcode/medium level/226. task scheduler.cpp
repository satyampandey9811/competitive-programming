// link to question - https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& a, int n) {
        if(n == 0) return a.size();
        int size = a.size();
        vector<int> store(26);
        for(int i = 0; i < size; i++) store[a[i] - 'A']++;
        int most = *max_element(store.begin(), store.end());
        int mostCount = 0;
        for(int i = 0; i < 26; i++) if(store[i] == most) mostCount++;                
        
        int partCount = most - 1;
        int partLength = n - (mostCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = size - most * mostCount;
        int idles = max(0, emptySlots - availableTasks);
        
        return size + idles;
    }
};