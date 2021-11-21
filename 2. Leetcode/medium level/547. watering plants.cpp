// link to question - https://leetcode.com/problems/watering-plants/

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size(), answer = 0;
        int c = capacity;
        
        for (int i = 0; i < n; i++) {
            c -= plants[i];
            answer++;
            
            if (i + 1 < n and plants[i+1] > c) {
                c = capacity;
                answer += 2 * (i + 1);
            }
        }
        
        return answer;
    }
};