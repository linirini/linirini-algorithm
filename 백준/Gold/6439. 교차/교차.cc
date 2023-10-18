#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int t;
pll l1, l2, p1, p2, p3, p4;
int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll ret = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (ret > 0) return 1;
	if (ret < 0) return -1;
	return 0;
}
bool isCross(pll a, pll b, pll c, pll d) {
	int ret1 = ccw(a.first, a.second, b.first, b.second, c.first, c.second)
		* ccw(a.first, a.second, b.first, b.second, d.first, d.second);
	int ret2 = ccw(c.first, c.second, d.first, d.second, a.first, a.second)
		* ccw(c.first, c.second, d.first, d.second, b.first, b.second);
	if (!ret1 && !ret2) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	else return ret1 <= 0 && ret2 <= 0;
}
bool isInside(pll& x) {
	return p1.first < x.first && x.first < p2.first
		&& p1.second < x.second && x.second < p3.second;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		pll tmp1, tmp2;
		cin >> l1.first >> l1.second >> l2.first >> l2.second
			>> tmp1.first >> tmp1.second >> tmp2.first >> tmp2.second;
		p1 = { min(tmp1.first, tmp2.first), min(tmp1.second, tmp2.second) };
		p2 = { max(tmp1.first, tmp2.first), min(tmp1.second, tmp2.second) };
		p3 = { min(tmp1.first, tmp2.first), max(tmp1.second, tmp2.second) };
		p4 = { max(tmp1.first, tmp2.first), max(tmp1.second, tmp2.second) };
		if ((isInside(l1) && isInside(l2))
			|| isCross(l1, l2, p1, p2)
			|| isCross(l1, l2, p1, p3)
			|| isCross(l1, l2, p4, p2)
			|| isCross(l1, l2, p4, p3))
			cout << "T\n";
		else cout << "F\n";
	}
}