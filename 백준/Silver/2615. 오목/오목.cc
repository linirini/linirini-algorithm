#include <iostream>
#include<algorithm>
using namespace std;
//#2615_오목
char board[19][19];
int dir[4][2] = { {0,1},{1,0},{1,1},{-1,1} };
bool visited[19][19][4][2];
char dfs(int x, int y, int d, char color, int cnt) {
	visited[x][y][d][color - '1'] = true;
	int nR = x + dir[d][0];
	int nC = y + dir[d][1];
	if (nR < 0 || nR >= 19 || nC < 0 || nC >= 19 || board[nR][nC] != color) {
		if (cnt == 5) return color;
		else return '0';

	}
	return dfs(nR, nC, d, color, cnt + 1);
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board[j][i] != '0') {
				for (int k = 0; k < 4; k++) {
					if (visited[j][i][k][board[j][i] - '1'])continue;
					if (dfs(j, i, k, board[j][i], 1) != '0') {
						cout << board[j][i] << '\n' << j + 1 << ' ' << i + 1;
						return 0;
					}
				}
			}
		}
	}
	cout << 0;
}