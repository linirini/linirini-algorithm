#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//#10423_전기가 부족해
int N, M, K, u, v, w,parent[1001],visited[1001],ans;
priority_queue<pair<int,pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
int find(int x) {
	if (parent[x] == -1)return -1;
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	if (y == -1)swap(x, y);
	parent[y] = x;
}
bool isAllConnected() {
	for (int i = 1; i <= N; i++)
		if (parent[i] != -1)return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)parent[i] = i;
	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;
		parent[x] = -1;
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		pq.push({ w,{u,v} });
	}
	while (!pq.empty()) {
		if (isAllConnected())break;
		int x = find(pq.top().second.first);
		int y = find(pq.top().second.second);
		int cost = pq.top().first;
		pq.pop();
		if (x != y) {
			merge(x, y);
			ans += cost;
		}
	}
	cout << ans;
}