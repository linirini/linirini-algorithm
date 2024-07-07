#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#11400_단절선
int V, E, seq, discovered[100001];
vector<int>adj[100001];
vector<pair<int,int>>edge;
int dfs(int A, int parent) {
	discovered[A] = ++seq;
	int ret = discovered[A];
	for (auto next : adj[A]) {
		if (next == parent) continue;
		if (!discovered[next]) {
			int low = dfs(next, A);
			if (low > discovered[A])edge.push_back({ min(A,next), max(A,next) });
			ret = min(ret, low);
		}
		else ret = min(ret, discovered[next]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	sort(edge.begin(), edge.end());
	cout << edge.size() << '\n';
	for (pair<int, int> i : edge) cout << i.first << ' ' << i.second << '\n';
}