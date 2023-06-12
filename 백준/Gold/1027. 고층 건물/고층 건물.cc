#include<iostream>
#include<algorithm>
using namespace std;
//#1027_고층 건물
int N, building[51],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> building[i];
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		double MaxL = 1e9,MaxR = -1e9;
		for (int j = i-1 ; j > 0 ; j--) {
			double grad = (building[i] - building[j]) / (double)(i - j);
			if (grad < MaxL) {
				cnt++;
				MaxL = grad;
			}
		}
		for (int j = i+1; j <=N ; j++) {
			double grad = (building[i] - building[j]) / (double)(i - j);
			if (grad > MaxR) {
				cnt++;
				MaxR = grad;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}