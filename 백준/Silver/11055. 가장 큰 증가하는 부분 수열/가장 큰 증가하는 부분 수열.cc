#include<iostream>
#include<algorithm>
using namespace std;
//#11055_가장 큰 증가하는 부분 수열
int N, A[1001], dp[1001],Max;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++)dp[i] = A[i];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < i; j++) 
			if (A[j] < A[i] && dp[i] < dp[j] + A[i]) dp[i] = dp[j] + A[i];
	sort(dp, dp + N);
	cout << dp[N - 1];
}