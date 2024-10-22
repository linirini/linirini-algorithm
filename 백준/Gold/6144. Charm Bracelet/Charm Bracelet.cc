#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//#6144_Charm Bracelet
int N, M, dp[12881], W[3403], V[3403];
int main(void) {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> V[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = M; j >=W[i]; j--) {
			if (W[i] <= j) {
				dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
			}
		}
	}
	cout << dp[M];
	return 0;
}
