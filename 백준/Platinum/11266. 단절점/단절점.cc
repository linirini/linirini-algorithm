#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#11266_단절점
int V, E, seq, discovered[10001], cnt;
bool point[10001];
vector<int>adj[10001];
int dfs(int A, bool isRoot) {
	discovered[A] = ++seq;
	int ret = discovered[A];
	int childCnt = 0;
	for (auto next : adj[A]) {
		if (!discovered[next]) {
			childCnt++;
			int low = dfs(next, false);
			if (!isRoot && low >= discovered[A])point[A] = true;
			ret = min(ret, low);
		}
		else ret = min(ret, discovered[next]);
	}
	if (isRoot && childCnt > 1)point[A] = true;
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
	for (int i = 1; i <= V; i++) {
		if (!discovered[i])dfs(i, true);
	}
	for (int i = 1; i <= V; i++) {
		if (point[i])cnt++;
	}
	cout << cnt << '\n';
	for (int i = 1; i <= V; i++) {
		if (point[i])cout << i << ' ';
	}
}