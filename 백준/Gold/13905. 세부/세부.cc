#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//#13905_세부
int N, M, s, e, h1, h2, k, parent[100001], visited[100001], cost[100001];
vector<pair<int, pair<int, int>>>edge;
vector<pair<int, int>>mst[100001];
queue<int>q;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) {
    return a.first > b.first;
}
int find(int x) {
    if (parent[x]==x)return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[x] = y;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> s >> e;
    for (int i = 1; i <= N; i++) parent[i] = i;
    for (int i = 1; i <= N; i++) cost[i] = 1e9;
	for (int i = 0; i < M; i++) {
		cin >> h1 >> h2 >> k;
		edge.push_back({ k,{h1,h2} });
	}
    sort(edge.begin(), edge.end(),cmp);
    for (int i = 0; i < edge.size(); i++) {
        if (find(edge[i].second.first) != find(edge[i].second.second)) {
            merge(edge[i].second.first, edge[i].second.second);
            mst[edge[i].second.first].push_back({ edge[i].second.second, edge[i].first });
            mst[edge[i].second.second].push_back({ edge[i].second.first, edge[i].first });
        }
    }
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (auto node : mst[here]) {
            int next = node.first;
            int nextCost = node.second;
            if (!visited[next]) {
                visited[next] = 1;
                cost[next] = min(cost[here], nextCost);
                q.push(next);
            }
        }
    }
    if (cost[e] == 1e9) cout << 0;
    else cout << cost[e];
}