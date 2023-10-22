#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
//#2166_다각형의 면적
using namespace std;
using ll = long long;
int N;
double ans;
struct P { ll x, y; };
vector<P>v;
double cross(P a, P b, P c) {
	long long ret = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)cin >> v[i].x >> v[i].y;
	for (int i = 1; i < v.size(); i++) ans += cross(v[0], v[i - 1], v[i]) / 2;
	printf("%.1lf", abs(ans));
}