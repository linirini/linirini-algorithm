#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
//#10976_피난
const int INF = 1e9;
int T, N, M, x, y;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		int cap[201][201], visited[201], ans = 0, flow[201][201];
		memset(flow, 0, sizeof(flow));
		memset(cap, 0, sizeof(cap));
		memset(visited, 0, sizeof(visited));
		vector<int>adj[201];
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			if (x == 1 || y == N)cap[x][y] = 1;
			else cap[x][y] =INF;
		}
		while (1) {
			fill(visited,visited+201, -1);
			queue<int>q;
			q.push(1);
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (int i = 0; i < adj[now].size(); i++) {
					int next = adj[now][i];
					if (cap[now][next] - flow[now][next] > 0 && visited[next] == -1) {
						q.push(next);
						visited[next] = now;
						if (next == N)break;
					}
				}
			}
			if (visited[N] == -1)break;
			int f = INF;
			for (int i = N; i != 1; i = visited[i]) {
				f = min(f, cap[visited[i]][i] - flow[visited[i]][i]);
			}
			for (int i = N; i != 1; i = visited[i]) {
				flow[visited[i]][i] += f;
				flow[i][visited[i]] -= f;
			}
			ans ++;
		}
		cout << ans<<'\n';
	}
}