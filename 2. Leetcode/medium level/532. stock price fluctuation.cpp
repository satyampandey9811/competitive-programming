// link to question - https://leetcode.com/problems/stock-price-fluctuation/

class StockPrice {
public:
    multiset<int> ms;
    map<int, int> m;
    
    StockPrice() {
        ms.clear();
        m.clear();
    }
    
    void update(int timestamp, int price) {
        if(m.count(timestamp)) {
            ms.erase(ms.find(m[timestamp]));
        }
        m[timestamp] = price;
        ms.insert(price);
    }
    
    int current() {
        return m.rbegin() -> second;
    }
    
    int maximum() {
        return *ms.rbegin();
    }
    
    int minimum() {
        return *ms.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */