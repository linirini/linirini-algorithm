#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
//#6086_최대 유량
//Edmand-Karp Algorithm:BFS
int cap[52][52], flow[52][52], visited[52], ans, N, S, T;
vector<int>adj[52];
int INF = 1e9;
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
int ctoi(char c) {
	if (c >= 'A' && c <= 'Z')return c - 'A';
	if (c >= 'a' && c <= 'z')return c - 'a' + 26;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char sour, sink;
		int c;
		cin >> sour >> sink >> c;
		S = ctoi(sink);
		T = ctoi(sour);
		adj[S].push_back(T);
		adj[T].push_back(S);
		cap[S][T] += c;
		cap[T][S] += c;
	}
	Edmand('A' - 'A', 'Z' - 'A');
	cout << ans;
}