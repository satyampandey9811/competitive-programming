// link to question - https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
public:
    map<int, pair<string, int>> cid;
    map<pair<string, string>, pair<int, int>> time;
    
    UndergroundSystem() {
        cid.clear(), time.clear();
    }
    
    void checkIn(int id, string stationName, int t) {                
        cid[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        int x = t - cid[id].second;
        time[{cid[id].first, stationName}].first += x;
        time[{cid[id].first, stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)time[{startStation, endStation}].first / time[{startStation, endStation}].second; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */