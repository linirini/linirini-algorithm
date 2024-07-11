#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//#1736_쓰레기 치우기
int N, M, cnt, board[101][101], trash;
void clean(int x, int y) {
	if (x == N - 1 && y == M - 1) {
		trash--;
		board[x][y] = 0;
	}
	for (int i = x; i < N; i++)
		for (int j = y; j < M; j++)
			if (board[i][j]) {
				board[i][j] = 0;
				trash--;
				clean(i, j);
				return;
			}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j]) trash++;
		}
	}
	while (trash > 0) {
		cnt++;
		if (board[0][0]) {
			board[0][0] = 0;
			trash--;
		}
		clean(0, 0);
	}
	cout << cnt;
}