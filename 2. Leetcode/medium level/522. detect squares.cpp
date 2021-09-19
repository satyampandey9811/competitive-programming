// link to question - https://leetcode.com/problems/detect-squares/

class DetectSquares {
public:
    map<pair<int, int>, int> m;
    vector<vector<int>> col;
    
    DetectSquares() {
        m.clear();
        col.clear();
        col.resize(1001);
    }
    
    void add(vector<int> a) {
        col[a[0]].push_back(a[1]);
        m[{a[0], a[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        
        int ans = 0, dist;
        for(int &i :col[x]) {
            if(i < y) {
                dist = y - i;
                ans += m[{x - dist, y}] * m[{x - dist, i}];
                ans += m[{x + dist, y}] * m[{x + dist, i}];
            }
            else if(i > y) {
                dist = i - y;
                ans += m[{x - dist, y}] * m[{x - dist, i}];
                ans += m[{x + dist, y}] * m[{x + dist, i}];
            }
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */