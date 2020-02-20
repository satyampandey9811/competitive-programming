// link to question - https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
    vector<int> a;
public:
    ProductOfNumbers() {
        a.empty();
    }
    
    void add(int num) {
        a.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        for(int i = a.size() - k; i < a.size(); i++)
            prod *= a[i];
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */