#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pll;
pll p1, p2, p3, p4;
int CCW(pll a, pll b, pll c) {
	long long ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	return !ret ? 0 : (ret < 0 ? -1 : 1);
}
bool isCross(pll a, pll b, pll c, pll d) {
	int ret1 = CCW(a,b,c)* CCW(a,b,d);
	int ret2 = CCW(c,d,a)* CCW(c,d,b);
	if (!ret1 && !ret2) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	else return ret1 <= 0 && ret2 <= 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;
	isCross(p1, p2, p3, p4) ? cout << 1 : cout << 0;
}