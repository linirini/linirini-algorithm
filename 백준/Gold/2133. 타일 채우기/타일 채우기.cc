#include<iostream>
#include<algorithm>
using namespace std;
//#2133_타일 채우기
int N,dp[31];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	dp[0] = 1; dp[1] = 0; dp[2] = 3;
	for (int i = 4; i <= N; i += 2) {
		for (int j = 2; j <= N; j += 2) {
			if (j == 2)dp[i] = dp[i - j] * dp[2];
			else if ((i - j) >= 0)dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[N];
}