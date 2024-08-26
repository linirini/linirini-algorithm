#include<iostream>
#include<algorithm>
using namespace std;
//#25634_전구 상태 뒤집기
int N, bolb[200001],onOff[200001], dp[200001], sum, diff = -5000;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> bolb[i];
	for (int i = 0; i < N; i++) {
		cin >> onOff[i];
		sum+= onOff[i] == 0 ? 0 : bolb[i];
	}
	dp[0] = onOff[0] == 0 ? bolb[0] : -bolb[0];
	diff = max(dp[0], diff);
	for (int i = 1; i < N; i++) {
		int val = onOff[i] == 0 ? bolb[i] : -bolb[i];
		dp[i] = max(dp[i-1] + val, val);
		diff = max(dp[i], diff);
	}
	cout << sum + diff;
}