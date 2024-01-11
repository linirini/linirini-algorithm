#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//#19542_전단지 돌리기
int N, S, D, x, y,visited[100001],ans;
vector<int>edge[100001];
int dfs(int now) {
	visited[now] = 1;
	int d = 0;
	for (auto next : edge[now]) {
		if (!visited[next]) {
			int result = dfs(next);
			if (result > D) ans += 2;
			d = max(d, result);
		}
	}
	return d + 1;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> S >> D;
	for (int i = 0; i < N-1; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(S);
	cout << ans;
}