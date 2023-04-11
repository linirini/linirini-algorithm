#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#5212_지구 온난화
int R, C,minr=11,minc=11,maxr=0,maxc=0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string map[11];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> map[i];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
						cnt++;
						continue;
					}
					if (map[nx][ny] == '.')cnt++;
				}
				if (cnt >= 3)map[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') {
				minc = min(minc, j);
				minr = min(minr, i);
				maxc = max(maxc, j);
				maxr = max(maxr, i);
			}
		}
	}
	for (int i = minr; i <= maxr; i++) {
		for (int j = minc; j <= maxc; j++) {
			map[i][j]=='X'?cout << map[i][j]:cout<<'.';
		}
		cout << '\n';
	}
}