#include<iostream>
#include<algorithm>
using namespace std;
//#11057_오르막 수
int N, dp[1001][10],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < 10; i++)dp[1][i] = 1;
	for(int i=2;i<=N;i++)
		for(int j=0;j<10;j++)
			for (int k = 0; k <= j; k++) 
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
	for (int i = 0; i < 10; i++)ans = (ans + dp[N][i])%10007;
	cout << ans;
}