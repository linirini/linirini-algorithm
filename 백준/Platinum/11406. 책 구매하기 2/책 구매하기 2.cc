#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
//#11406_책 구매하기 2
const int INF = 1e9,SOURCE = 201, SINK = 202;
int N, M, x, y;
int cap[205][205], visited[205], ans, flow[205][205];
vector<int>adj[205];
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
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cap[i][SINK];
		adj[i].push_back(SINK);
		adj[SINK].push_back(i);
	}
	for (int i = N; i < N+M; i++) {
		cin >> cap[SOURCE][i];
		adj[i].push_back(SOURCE);
		adj[SOURCE].push_back(i);
	}
	for (int i = N; i < N+M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cap[i][j];
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	Edmand(SOURCE,SINK);
	cout << ans << '\n';
}