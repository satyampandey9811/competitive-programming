// link to question - https://leetcode.com/problems/online-stock-span/

class StockSpanner {
    vector<int> a;
    int val;
    int c;
public:
    StockSpanner() {
        val = INT_MAX;
        c = 0;
    }
    
    int next(int price) {
        a.push_back(price);
        if(price < val) {
            val = price;
            c = 0;
            return 1;
        }
        c++;
        int ans = c;
        for(int i = a.size() - 1 - c; i >= 0; i--) {
            if(a[i] <= price) ans++;
            else break;
            c++;
        }
        val = price;
        return ans;
    }
};