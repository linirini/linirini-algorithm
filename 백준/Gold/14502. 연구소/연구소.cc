#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<string.h>
using namespace std;
//#14502_연구소
int N, M, board[10][10],ans,after[10][10],tmp[10][10];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int visited[10][10];
queue<pair<int, int>>q;
void bfs() {
	int after[10][10],cnt=0;
	memcpy(after, tmp, sizeof(tmp));
	queue<pair<int, int>>tmpq=q;
	while(!tmpq.empty()) {
		int x = tmpq.front().first;
		int y = tmpq.front().second;
		tmpq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && after[nx][ny] == 0) {
				after[nx][ny] = 2;
				tmpq.push({ nx,ny });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (after[i][j] == 0)cnt++;
		}
	}
	ans = max(ans, cnt);
}
void go(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!tmp[i][j]) {
				tmp[i][j] = 1;
				go(cnt + 1);
				tmp[i][j] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)q.push({ i,j });
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board[i][j]) {
				memcpy(tmp, board, sizeof(board));
				tmp[i][j] = 1;
				go(1);
				tmp[i][j] = 0;
			}
		}
	}
	cout << ans;
}
