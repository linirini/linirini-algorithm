#include<iostream>
#include<algorithm>
using namespace std;
//#17845_수강 과목
int N, K, dp[1001][10001];
struct Subject {
	int I;
	int T;
};
Subject s[10001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= K; i++)cin >> s[i].I >> s[i].T;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (j >= s[i].T)dp[i][j] = max(dp[i - 1][j], dp[i-1][j - s[i].T] + s[i].I);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[K][N];
}