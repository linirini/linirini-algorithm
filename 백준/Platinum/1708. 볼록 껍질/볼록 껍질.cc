#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
using ll = long long;
int N;
struct P { ll x, y; };
vector<P>v;
ll dist(P a, P b) {
	return pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
}
int CCW(P a, P b, P c) {
	long long ret = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	//return <= 0 : NOT CCW 
	return !ret ? 0 : (ret < 0 ? -1 : 1);
}
bool cmp(P a, P b) {
	int chk = CCW(v[0], a, b);
	if (chk)return chk > 0 ? true : false;
	if (dist(v[0], a) < dist(v[0], b)) return true;
	return false;
}
vector<P> Graham() {
	vector<P> nv;
	for (int i = 0; i < N; i++) {
		while (2 <= nv.size() && CCW(nv[nv.size() - 2], nv[nv.size() - 1], v[i]) <= 0) {
			nv.pop_back();
		}
		nv.push_back(v[i]);
	}
	return nv;
}
int ConvexHull() {
	//step 1 : 기준점 잡기
	int idx = 0;
	for (int i = 1; i < N; i++) {
		if (v[idx].y > v[i].y || (v[idx].y == v[i].y && v[idx].x > v[i].x))idx = i;
	}
	swap(v[idx], v[0]);
	//step 2 : 반시계방향으로 정렬
	sort(v.begin() + 1, v.end(), cmp);
	//step 3 : 그레이엄 스캔
	vector<P>ret = Graham();
	return ret.size();
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)cin >> v[i].x >> v[i].y;
	cout << ConvexHull();
}