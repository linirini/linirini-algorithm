#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<queue>
using namespace std;
//#9207_페그 솔리테어
int N, ansCnt = 1e9, ansRemain = 1e9;;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void go(string board[51]) {
	for(int i=0;i<5;i++){
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 'o') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					int nx2 = i + dx[k] * 2;
					int ny2 = j + dy[k] * 2;
					if (nx >= 0 && nx < 5 && ny >= 0 && ny < 9 && nx2 >= 0 && nx2 < 5 && ny2 >= 0 && ny2 < 9) {
						if (board[nx][ny]=='o'&&board[nx2][ny2]=='.') {
							board[i][j] = '.';
							board[nx][ny] = '.';
							board[nx2][ny2] = 'o';
							go(board);
							board[i][j] = 'o';
							board[nx][ny] = 'o';
							board[nx2][ny2] = '.';
						}
					}
				}
			}
		}
	}
	int remain = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
			if (board[i][j] == 'o')remain++;
	ansRemain = min(ansRemain, remain);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0);
	cin >> N;
	while (N--) {
		ansCnt = 0, ansRemain = 1e9;
		string board[101];
		for (int i = 0; i < 5; i++) {
			cin >> board[i];
			for (int j = 0; j < 9; j++)if (board[i][j] == 'o')ansCnt++;
		}
		go(board);
		cout << ansRemain << ' ' << ansCnt-ansRemain << '\n';
	}
}