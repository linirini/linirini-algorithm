#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//#17835_면접보는 승범이네
using pll=pair<long long, long long>;
const long long INF = 1e18;
int N, M, K,U,V,C;
vector<pll>edge[100001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> U >> V >> C;
		edge[V].push_back({U,C});
	}
	vector<long long>ans(N + 1, INF);
	vector<long long>dist(N + 1, INF);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	for (int i = 0; i < K; i++) {
		int st;
		cin >> st;
		dist[st] = 0;
		pq.push({ 0,st });
	}
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost)continue;
		for (auto node : edge[now]) {
			int next = node.first;
			int nextCost = node.second;
			if (dist[next] > dist[now] + nextCost) {
				dist[next] = dist[now] + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
	for (int i = 1; i <= N; i++)ans[i] = min(ans[i], dist[i]);
	long long ansCost=-1, ansNum=0;
	for (int i = 1; i <= N; i++)
		if (ans[i] > ansCost) {
			ansCost = ans[i];
			ansNum = i;
		}
	cout << ansNum << '\n' << ansCost;
}