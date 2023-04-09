#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
//#1261_알고스팟
int N, M, board[101][101],dp[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs() {
	queue<pair<int, int>>q;
	q.push({ 1,1 });
	dp[1][1] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
				if (!board[nx][ny] && dp[x][y] < dp[nx][ny]) {
					q.push({ nx,ny });
					dp[nx][ny] = dp[x][y];
				}
				else if (board[nx][ny] == 1 && dp[x][y] + 1 < dp[nx][ny]) {
					q.push({ nx,ny });
					dp[nx][ny] = dp[x][y] + 1;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			dp[i][j] = 1e9;
	bfs();
	cout << dp[N][M];
}