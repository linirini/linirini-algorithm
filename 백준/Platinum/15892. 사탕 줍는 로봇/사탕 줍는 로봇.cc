#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<string.h>
using namespace std;
//#15892_사탕 줍는 로봇
const int INF = 1e9;
int n, m, a, b, c;
int cap[301][301], flow[301][301], visited[301], ans;
vector<int>adj[301];
void Edmand(int Sour, int Sink) {
	while (1) {
		memset(visited, -1, sizeof(visited));
		queue<int>q;
		q.push(Sour);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now][i];
				if (cap[now][next] - flow[now][next] > 0 && visited[next] == -1) {
					q.push(next);
					visited[next] = now;
					if (next == Sink)break;
				}
			}
		}
		if (visited[Sink] == -1)break;
		int f = INF;
		for (int i = Sink; i != Sour; i = visited[i]) {
			f = min(f, cap[visited[i]][i] - flow[visited[i]][i]);
		}
		for (int i = Sink; i != Sour; i = visited[i]) {
			flow[visited[i]][i] += f;
			flow[i][visited[i]] -= f;
		}
		ans += f;
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		cap[a][b] += c;
		cap[b][a] += c;
	}
	Edmand(1, n);
	cout << ans << '\n';
}