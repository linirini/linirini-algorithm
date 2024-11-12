#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//#11377_열혈강호 3
int N, M, K, visited[1001], match[1001], ans;
vector<int> node[1001];
int dfs(int here) {
	for (int i = 0; i < node[here].size(); i++) {
		int next = node[here][i];
		if (visited[next])continue;
		visited[next] = 1;
		if (!match[next] || dfs(match[next])) {
			match[next] = here;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int t;
			cin >> t;
			node[i].push_back(t);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		fill(visited, visited + 1001, 0);
		if (dfs(i))ans++;
	}
	for (int i = 1; i <= N; i++) {
		fill(visited, visited + 1001, 0);
		if (dfs(i)) {
			ans++;
			cnt++;
		}
		if (cnt == K)break;
	}
	cout << ans;
}