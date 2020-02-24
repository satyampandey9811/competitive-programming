// link to question - https://www.codechef.com/FEB20B/problems/LONGCOOK

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define md 1000000007

bool leapyear(int y){
    return (y % 400 == 0) or (y % 4 == 0 and y % 100 != 0);
}

int result(int y){
    int d = 3, ans = 0;
    for(int i = 1; i <= y; i++){
        d = d % 7;
        bool ly = true;
        if(leapyear(i)){
            if(d == 5)
                ans++;
        }
        else{
            ly = false;
            if(d == 5 or d == 6)
                ans++;
        }
        d++;
        if(ly) d++;
    }
    return ans;
}

int calc(int y){
    int ans = 0;
    ans += (y / 400) * 101;
    y = y % 400;
    ans += result(y);
    return ans;
}

void testcase(){
    int m1, m2, y1, y2;
    cin >> m1 >> y1 >> m2 >> y2;
    if(m1 > 2) y1++;
    if(m2 < 2) y2--;
    cout << calc(y2) - calc(y1 - 1);
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        testcase();
        cout << '\n';
    }
    return 0;
}