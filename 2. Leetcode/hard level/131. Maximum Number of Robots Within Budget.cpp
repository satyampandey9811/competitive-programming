// link to question - https://leetcode.com/problems/maximum-number-of-robots-within-budget/

class Solution {
public:
    /**************  segment tree code starts  ***************/

    vector<int> tree;

    void build (int i, int s, int e, vector<int>& a) {
        if(s == e) tree[i] = a[s];
        else {
            int mid = (s + e) / 2;
            build(2 * i, s, mid, a);
            build(2 * i + 1, mid + 1, e, a);
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int query (int i, int s, int e, int l, int r) {
        if(s > r or e < l) return INT_MIN;
        if(s >= l and e <= r) return tree[i];

        int mid = (s + e) / 2;
        int left = query(2 * i, s, mid, l, r);
        int right = query(2 * i + 1, mid + 1, e, l, r);
        return max(left, right);
    }

    /**************  segment tree code ends  ***************/
    
    int n;
    
    int go (vector<int>& a, vector<int>& b, vector<long long>& pre, long long& bud, int k) {
        long long sum = 0;
        
        for (int i = 0; i <= n - k; i++) {
            sum = query (1, 0, n - 1, i, i + k - 1) + k * 1LL * (pre[i + k] - pre[i]);
            if (sum <= bud) return 1;
        }
        
        return 0;
    }
    
    int maximumRobots(vector<int>& a, vector<int>& b, long long bud) {
        n = a.size();
        int low = 0, high = n, mid, ans;
        tree = vector<int>(4 * n);
        build (1, 0, n - 1, a);
        
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = b[i] + pre[i];
        }
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (go(a, b, pre, bud, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return ans;
    }
};