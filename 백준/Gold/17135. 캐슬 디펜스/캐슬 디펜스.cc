#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
//#17135_캐슬 디펜스
int N, M, D, board[17][17], tmp_board[17][17], visited[16], ans;
vector<vector<int>>archers;
void go(int num, int cnt) {
	if (cnt == 3) {
		vector<int>tmp;
		for (int i = 1; i <= M; i++) if (visited[i])tmp.push_back(i);
		archers.push_back(tmp);
	}
	else {
		for (int i = num; i <= M; i++){
			if (visited[i]) continue;
			visited[i] = 1;
			go(i, cnt + 1);
			visited[i] = 0;
		}
	}
}
void copy_array() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			tmp_board[i][j] = board[i][j];
}
int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y2 - y1);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);;
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	go(1, 0);
	for (int i = 0; i < archers.size(); i++) {
		copy_array();
		set<pair<int, int>>attacked;
		int cnt = 0, last_line = N;
		while (last_line) {
			for (auto pos : archers[i]) {
				int minR=17, minC=17, minDist = 50;
				for (int r = 1; r <= last_line; r++) {
					for (int c = 1; c <= M; c++) {
						int d = dist(last_line + 1, pos, r, c);
						if (tmp_board[r][c] && d <= D) {
							if (d < minDist) {
								minDist = d;
								minR = r;
								minC = c;
							}
							else if (d == minDist && c < minC) {
									minDist = d;
									minR = r;
									minC = c;
							}
						}
					}
				}
				if (minDist <= D) {
					if (attacked.find({minR,minC})==attacked.end())cnt++;
					attacked.insert({ minR,minC });
				}
			}
			for (auto now : attacked) tmp_board[now.first][now.second] = 0;
			last_line--;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}