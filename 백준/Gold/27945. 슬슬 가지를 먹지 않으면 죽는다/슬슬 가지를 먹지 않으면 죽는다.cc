#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
//#27945_슬슬 가지를 먹지 않으면 죽는다.
int N, M, a, b, c, visited[100001], ans;
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>edge[100001];
vector<int>chk;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c});
		edge[b].push_back({ a, c});
	}
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (!visited[now]) {
			visited[now] = 1;
			chk.push_back(cost);
			for (auto node : edge[now]) {
				int next = node.first, ncost = node.second;
				if (!visited[next])pq.push({ ncost, next });
			}
		}
	}
	sort(chk.begin(), chk.end());
	for (int i = 0; i < chk.size();i++) {
		if(ans==chk[i]) ans++;
		else break;
	}
	cout << ans;
}