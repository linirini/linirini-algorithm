#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
//#20010_악덕 영주 혜유
int N, K, a, b, c,ans,Max,parent[1001],st,visited[1001];
priority_queue<pair<int, pair<int, int>>>pq;
vector<pair<int,int>>edge[1001];
int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)parent[y] = x;
}
void go(int now, int cost) {
	if (cost > Max) {
		Max = cost;
		st = now;
	}
	for (auto next : edge[now]) {
		if (!visited[next.first]) {
			visited[next.first] = 1;
			go(next.first, cost + next.second);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)parent[i] = i;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c;
		pq.push({ -c,{a,b } });
		pq.push({ -c,{b,a } });
	}
	while (!pq.empty()) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int c = -pq.top().first;
		pq.pop();
		if (find(u) != find(v)){
			edge[u].push_back({ v,c });
			edge[v].push_back({ u,c });
			merge(u, v);
			ans += c;
		}
	}
	visited[0] = 1;
	go(0, 0);
	Max = 0;
	fill(visited, visited + N, 0);
	visited[st] = 1;
	go(st, 0);
	cout << ans << '\n' << Max;
}