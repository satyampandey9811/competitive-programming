// link to question - https://leetcode.com/problems/largest-component-size-by-common-factor/

/***************  disjoint set union code starts  *****************/

class unionFind {

private:
    vector<int> setSize;
    vector<int> parent;
    int totalComponents;
    int maxSetSize;

public:
    unionFind(int n) {
        setSize = vector<int>(n, 1);
        parent = vector<int>(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        totalComponents = n;
        maxSetSize = 1;
    }

    // uses path compression which takes amortized constant time.
    int find(int x) {
        int root = x;
        while(root != parent[root]) root = parent[root];
        while(x != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    // uses union by rank 
    void unify(int g, int h) {
        if(connected(g, h)) return;
        int root1 = find(g);
        int root2 = find(h);
        if(setSize[g] < setSize[h]) {
            parent[root1] = root2;
            setSize[root2] += setSize[root1];
        }
        else {
            parent[root2] = root1;
            setSize[root1] += setSize[root2];
        }
        totalComponents--;
        maxSetSize = max({maxSetSize, setSize[root1], setSize[root2]});
    }

    // returns true if g and h are connected else returns false.
    bool connected(int g, int h) {
        return find(g) == find(h);
    }

    // returns the size of the component/set to which 'g' belongs
    int componentSize(int g) {
        return setSize[find(g)];
    }

    // returns the number of components/sets at the moment
    int components() {
        return totalComponents;
    }

    // returns the maximum set size among all the components
    int maxComponentSize() {
        return maxSetSize;
    }
};

/***************  disjoint set union code ends  *****************/

class Solution {
public:
    int largestComponentSize(vector<int>& a) {
        int n = a.size(), num;
        vector<int> prime(1e5, -1);
        unionFind uf(n);
        
        for (int i = 0; i < n; i++) {
            num = a[i];
            
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    if (prime[j] != -1) {
                        uf.unify(prime[j], i);
                    }
                    else {
                        prime[j] = i;
                    }
                    
                    while (num % j == 0) {
                        num /= j;
                    }
                }
            }
            
            if (num > 1) {
                if (prime[num] != -1) {
                    uf.unify(prime[num], i);
                }
                else {
                    prime[num] = i;
                }
            }
        }
        
        return uf.maxComponentSize();
    }
};