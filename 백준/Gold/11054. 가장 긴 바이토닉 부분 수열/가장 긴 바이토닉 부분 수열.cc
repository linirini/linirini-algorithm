#include<iostream>
#include<algorithm>
using namespace std;
//#11054_가장 긴 바이토닉 부분 수열
int N, A[1001], dp[1001], revDp[1001],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		revDp[i] = 1;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++) 
			if (A[j] < A[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
	for (int i = N - 1; i >= 0; i--) 
		for(int j=N-1;j>i;j--)
			if (A[j] < A[i] && revDp[i] < revDp[j] + 1) revDp[i] = revDp[j] + 1;
	for (int i = 0; i < N; i++)
		ans = max(ans, dp[i] + revDp[i] - 1);
	cout << ans;
}