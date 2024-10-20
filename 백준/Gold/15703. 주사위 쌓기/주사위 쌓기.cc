#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#15703_주사위 쌓기
int N, towerCnt, usedCnt, height;
vector<int>tower;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		tower.push_back(x);
	}
	sort(tower.begin(), tower.end());
	while (usedCnt != N) {
		height = 0;
		towerCnt++;
		for (int j = 0; j < N; j++) {
			if (tower[j] == -1)continue;
			if (height <= tower[j]) {
				height++;
				usedCnt++;
				tower[j] = -1;
			}
		}
		
	}
	cout << towerCnt;
}