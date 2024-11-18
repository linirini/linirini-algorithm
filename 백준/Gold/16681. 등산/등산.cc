#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
//#16681_등산
int N, M, D, E;
vector<pair<int, int>> edge[100001];
long long dist[100001];
long long distUp[100001];
long long distDown[100001];
int height[100001];
priority_queue<pair<long long, long long>,vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
void dijkstra(int st) {
	fill(dist, dist+N,1e14);
	dist[st] = 0;
	q.push({ 0, st });
	while (!q.empty()) {
		int now = q.top().second;
		long long cost = q.top().first;
		q.pop();
		if (dist[now] < cost) continue;
		for (int i = 0; i < edge[now].size(); i++) {
			int nextNode = edge[now][i].first;
			long long nextCost = edge[now][i].second;
			if (height[nextNode] <= height[now]) continue;
			if (dist[nextNode] > cost + nextCost) {
				dist[nextNode] = cost + nextCost;
				q.push({ dist[nextNode], nextNode });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; i++) cin >> height[i];
	for (int i = 1; i <= M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		edge[x].push_back({ y, c });
		edge[y].push_back({ x, c });
	}
	dijkstra(1);
	for (int i = 1; i <= N; i++) distUp[i] = dist[i];
	dijkstra(N);
	for (int i = 1; i <= N; i++) distDown[i] = dist[i];
	long long ans = -1e14;
	for (int i = 2; i < N; i++) {
		if (distUp[i] == 1e14 || distDown[i] == 1e14) continue;
		long long sum = height[i] * E - (distUp[i] + distDown[i]) * D;
		ans = max(ans, sum);
	}
	if (ans == -1e14) cout << "Impossible";
	else cout << ans;
}