#include<iostream>
#include<algorithm>
using namespace std;
//#2578_빙고
int bingo[5][5],n[26];
pair<int, int>pos[26];
int check() {
	int ans = 0, flag = 1;
	for (int i = 0; i < 5; i++) {
		flag = 1;
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j]) {
				flag = 0;
				break;
			}
		}
		if (flag)ans++;
	}
	for (int j = 0; j < 5; j++) {
		flag = 1;
		for (int i = 0; i < 5; i++) {
			if (bingo[i][j]) {
				flag = 0;
				break;
			}
		}
		if (flag)ans++;
	}
	flag = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][i]) {
			flag = 0;
			break;
		}
	}
	if (flag)ans++;
	flag = 1;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][4-i]) {
			flag = 0;
			break;
		}
	}
	if (flag)ans++;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> bingo[i][j];
			pos[bingo[i][j]] = { i,j };
		}
	}
	for (int i = 1; i <= 25; i++)cin >> n[i];
	for (int i = 1; i <= 25; i++) {
		bingo[pos[n[i]].first][pos[n[i]].second] = 0;
		if (i < 4)continue;
		int res = check();
		if (res >= 3) {
			cout << i;
			return 0;
		}
	}
}