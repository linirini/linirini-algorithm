#include<iostream>
#include<algorithm>
using namespace std;
//#11727_2*n 타일링 2
int n, dp[1001][4];
int main() {
	cin >> n;
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
	dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3])%10007;
		dp[i][2] = ((dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) * dp[2][2])%10007;
		dp[i][3] = ((dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) * dp[2][3])%10007;
	}
	cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 10007;
}
