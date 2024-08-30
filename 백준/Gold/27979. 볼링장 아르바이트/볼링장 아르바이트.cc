#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#27979_볼링장 아르바이트
int N, w[200001], visited[200001], Max, ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	int moved = 0;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
		Max = max(Max, w[i]);
		if (Max > w[i]) {
			ans++;
			visited[i] = 1;
			moved = max(moved, w[i]);
		}
	}
	for (int i = 0; i < N; i++) if (!visited[i] && moved > w[i])ans++;
	cout << ans;
}