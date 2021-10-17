// link to question - https://leetcode.com/problems/simple-bank-system/

class Bank {
public:
    int n;
    vector<long long> b;
    
    Bank(vector<long long>& balance) {
        b = balance;
        n = b.size();
    }
    
    bool transfer(int a1, int a2, long long money) {
        if(a1 < 1 or a2 < 1 or a1 > n or a2 > n) return 0;
        if(b[a1 - 1] >= money) {
            b[a1 - 1] -= money;
            b[a2 - 1] += money;
            return 1;
        }
        return 0;
    }
    
    bool deposit(int a, long long money) {
        if(a < 1 or a > n) return 0;
        b[a-1] += money;
        return 1;
    }
    
    bool withdraw(int a, long long money) {
        if(a < 1 or a > n) return 0;
        if(b[a-1] < money) return 0;
        b[a-1] -= money;
        return 1;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */