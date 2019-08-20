// link to question - https://www.codechef.com/JULY19B/problems/PRTAGN/

#include <bits/stdc++.h>

using namespace std;

void testcase() {
	int q, x, z, e1 = 0, o1 = 0, c = 0;
	int f, g, d;
	cin >> q;
	set<int> a;
	for (int i = 1; i <= q; i++) {
		cin >> x;
		f = a.size();
		a.insert(x);
		if (f != a.size()) {
			d = x;
			while (d > 0) {
				if (d % 2)
					c++;
				d = d / 2;
			}
			if (c % 2 == 0)
				e1++;
			else
				o1++;
			c = 0;
		}
		else {
			cout << e1 << ' ' << o1 << endl;
			continue;
		}

		for (auto y : a) {
			if (x != y) {
				z = x ^ y;
				g = a.size();
				a.insert(z);
				if (g != a.size()) {
					int d = z;
					while (d > 0) {
						if (d % 2)
							c++;
						d = d / 2;
					}
					if (c % 2 == 0)
						e1++;
					else
						o1++;
					c = 0;
				}
			}
		}

		cout << e1 << ' ' << o1 << endl;
	}
}

int main() {
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