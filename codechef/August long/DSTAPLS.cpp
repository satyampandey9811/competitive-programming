// link to question - https://www.codechef.com/AUG19B/problems/DSTAPLS/

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	long long n,k;
	cin >> n >> k;
	if (k == 1) {
		cout << "NO";
		return;
	}
	long long a = n / k;
	if (a%k==0) {
		cout << "NO";
		return;
	}
	cout << "YES";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef SP
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif	
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout << "Case #" << i << ": ";
		testcase();
		cout << '\n';
	}
	return 0;
}