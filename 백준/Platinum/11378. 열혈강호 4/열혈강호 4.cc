#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
//#11378_열혈강호 4
const int INF = 1e9,SOURCE = 2001, SINK = 2002,PENALTY=2003, BIAS = 1000;
int N, M, K, cap[2005][2005], visited[2005], ans, flow[2005][2005];
vector<int>adj[2005];
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
	cin >> N >> M >> K;
	cap[SOURCE][PENALTY] = K;
	adj[PENALTY].push_back(SOURCE);
	adj[SOURCE].push_back(PENALTY);
	for (int i = 1; i <= M; i++) {
		cap[i+BIAS][SINK] = 1;
		adj[i+BIAS].push_back(SINK);
		adj[SINK].push_back(i+BIAS);
	}
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int n;
			cin >> n;
			cap[i][BIAS + n] = 1;
			adj[BIAS + n].push_back(i);
			adj[i].push_back(BIAS + n);
		}
		cap[SOURCE][i]=1;
		adj[i].push_back(SOURCE);
		adj[SOURCE].push_back(i);
		cap[PENALTY][i] = K;
		adj[PENALTY].push_back(i);
		adj[i].push_back(PENALTY);
	}
	Edmand(SOURCE, SINK);
	cout << ans;
}