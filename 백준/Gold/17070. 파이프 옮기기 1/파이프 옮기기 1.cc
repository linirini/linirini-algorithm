#include<iostream>
#include<algorithm>
using namespace std;
//#17070_파이프 옮기기 1
int N, board[17][17],cnt;
int dx[3] = { 0,1,1 };
int dy[3] = { 1,1,0 };
void go(int x, int y,int by) {
	if (x == N && y == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if ((by == 0 && i == 2) || (by == 2 && i == 0))continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if (i == 1) {
				if (board[nx - 1][ny] == 1 || board[nx][ny - 1] == 1) continue;
			}
			if(!board[nx][ny]) go(nx, ny, i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	go(1, 2, 0);
	cout << cnt;
}