// link to question - https://leetcode.com/problems/apply-discount-every-n-orders/

class Cashier {
    vector<int> products, prices;
    int c = 0, num, dis;
public:
    Cashier(int n, int d, vector<int>& prod, vector<int>& price) {
        num = n;
        dis = d;
        for(int i = 0; i < prod.size(); i++) products.push_back(prod[i]);
        for(int i = 0; i < price.size(); i++) prices.push_back(price[i]);
    }
    
    double getBill(vector<int> product, vector<int> amt) {
        double bill = 0.0;
        c++;
        for(int i = 0; i < product.size(); i++){
            int y = product[i];
            auto it = find(products.begin(), products.end(), y);
            int p = distance(products.begin(), it);
            bill += prices[p] * amt[i];
        }
        if(c == num){
            bill -= (bill * dis) / 100;
            c = 0;
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */