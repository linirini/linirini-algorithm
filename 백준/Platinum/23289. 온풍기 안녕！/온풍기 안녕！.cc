#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
//#23289_온풍기 안녕!
struct Heat {
	int r;
	int c;
	int dir;
};
int R, C, K, board[21][21], W, x, y, t, wall[21][21][5],ans, wind[21][21],currentBlow[21][21];
vector<Heat>heaters;
vector<pair<int, int>>testTargets;
int dx[5] = { 0, 0,0,-1,1 };
int dy[5] = { 0, 1,-1,0,0 };
pair<int, int>windDir[5][3] =
{ {{0,0},{0,0},{0,0} },
{{-1,1},{0,1},{1,1} },
{{-1,-1},{0,-1},{1,-1} },
{{-1,-1},{-1,0},{-1,1} },
{{1,-1},{1,0},{1,1} } };
void initCurrentBlow() {
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			currentBlow[i][j] = 0;
}
void addWind() {
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			wind[i][j]+=currentBlow[i][j];
}
void blowWind(int windStrength, int x, int y, int dir) {
	if (!windStrength) return;
	currentBlow[x][y] = windStrength;
	int nx = x + windDir[dir][0].first;
	int ny = y + windDir[dir][0].second;
	if ((dir == 1 || dir == 2) && nx >= 1 && nx <= R && ny >= 1 && ny <= C && !currentBlow[nx][ny] && !wall[x][y][3] && !wall[x - 1][y][dir])
		blowWind(windStrength - 1, nx, ny, dir);
	if ((dir == 3 || dir == 4) && nx >= 1 && nx <= R && ny >= 1 && ny <= C && !currentBlow[nx][ny] && !wall[x][y][2] && !wall[x][y - 1][dir])
		blowWind(windStrength - 1, nx, ny, dir);
	nx = x + windDir[dir][1].first;
	ny = y + windDir[dir][1].second;
	if ((dir == 1 || dir == 2) && nx >= 1 && nx <= R && ny >= 1 && ny <= C && !currentBlow[nx][ny] && !wall[x][y][dir])
		blowWind(windStrength - 1, nx, ny, dir);
	if ((dir == 3 || dir == 4) && nx >= 1 && nx <= R && ny >= 1 && ny <= C && !currentBlow[nx][ny] && !wall[x][y][dir])
		blowWind(windStrength - 1, nx, ny,dir);
	nx = x + windDir[dir][2].first;
	ny = y + windDir[dir][2].second;
	if ((dir == 1 || dir == 2) && nx >= 1 && nx <= R && ny >= 1 && ny <= C && !currentBlow[nx][ny] && !wall[x][y][4] && !wall[x + 1][y][dir])
		blowWind(windStrength - 1, nx, ny, dir);
	if ((dir == 3 || dir == 4) && nx >= 1 && nx <= R && ny >= 1 && ny <= C && !currentBlow[nx][ny] && !wall[x][y][1] && !wall[x][y + 1][dir])
		blowWind(windStrength - 1, nx, ny, dir);
}
void heat() {
	for (int i = 0; i < heaters.size(); i++) {
		initCurrentBlow();
		int x = heaters[i].r;
		int y = heaters[i].c;
		int dir = heaters[i].dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		blowWind(5, nx, ny,dir);
		addWind();
	}
}
void controlTemperature() {
	initCurrentBlow();
	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			int temperature = wind[x][y];
			for (int k = 1; k <= 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				int flag = 0;
				if (nx >= 1 && nx <= R && ny >= 1 && ny <= C) 
					if ((k == 1 || k == 4) && !wall[x][y][k])flag = 1;
				if (!flag) continue;
				int nextTemperature = wind[nx][ny];
				int diff = abs(temperature - nextTemperature);
				diff /= 4; 
				if (temperature > nextTemperature) {
					currentBlow[x][y] -= diff;
					currentBlow[nx][ny] += diff; 
				}
				else if (temperature < nextTemperature) {
					currentBlow[x][y] += diff;
					currentBlow[nx][ny] -= diff;
				}
			}
		}
	}
	addWind();
}
void decreaseTemperature() {
	for (int i = 1; i <= C; i++) if (wind[1][i]) wind[1][i]--;
	for (int i = 1; i <= C; i++) if (wind[R][i]) wind[R][i]--;
	for (int i = 2; i < R; i++) if (wind[i][1]) wind[i][1]--;
	for (int i = 2; i < R; i++) if (wind[i][C])	wind[i][C]--;
}
void eatChocolate() {
	ans++;
}
bool isWindAllMoreThanK() {
	for (auto target : testTargets)
		if (wind[target.first][target.second] < K) return false;
	return true;
}
void test() {
	while (1) {
		heat();
		controlTemperature();
		decreaseTemperature();
		eatChocolate();
		if (ans > 100) {
			ans = 101;
			break;
		}
		if (isWindAllMoreThanK())break;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 5)heaters.push_back({ i,j,board[i][j] });
			else if (board[i][j] == 5) testTargets.push_back({ i,j });
		}
	cin >> W;
	for (int i = 0; i < W; i++) {
		cin >> x >> y >> t;
		if (!t) {
			wall[x][y][3] = 1;
			wall[x - 1][y][4] = 1;
		}
		else {
			wall[x][y][1] = 1;
			wall[x][y + 1][2] = 1;
		}
	}
	test();
	cout << ans;
}