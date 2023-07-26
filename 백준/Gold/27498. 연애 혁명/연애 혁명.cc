#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#27498_연애 혁명
int N, M, a,b,c,d,par[10001], total;
priority_queue<pair<int,pair<int, int>>>pq;
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)par[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) par[i] = i;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		if (d) merge(a,b);
		else {
			pq.push({ c, {a,b} });
			pq.push({ c, {b,a} });
			total += c;
		}
	}
	while (!pq.empty()) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (find(u) != find(v)) {
			merge(u, v);
			total -= cost;
		}
	}
	cout << total;
}