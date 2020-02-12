// link to question - https://leetcode.com/problems/distance-between-bus-stops/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int totald=0;
        for(int i=0;i<distance.size();i++)
            totald+=distance[i];
        int d1=0,d2;
        if(destination>=start){
            for(int i=start;i<destination;i++)
                d1+=distance[i];
        }
        else{
            for(int i=destination;i<start;i++)
                d1+=distance[i];
        }
        d2=totald-d1;
        return min(d1,d2);
    }
};