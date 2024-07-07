#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#11266_단절점
int T, N, M, seq, discovered[30001], cnt;
bool point[30001];
vector<int>adj[30001];
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
	cin >> T;
	while (T--) {
		cin >> N >> M;
		fill(point, point + N, false);
		fill(discovered, discovered + N, false);
		for (int i = 0; i <= N; i++)adj[i].clear();
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= N; i++) if (!discovered[i])dfs(i, true);
		int flag = 0;
		for (int i = 1; i <= N; i++) {
			if (point[i]) {
				flag = 1;
				cout << "YES" << '\n';
				break;
			}
		}
		if(!flag)cout << "NO" << '\n';
	}
}