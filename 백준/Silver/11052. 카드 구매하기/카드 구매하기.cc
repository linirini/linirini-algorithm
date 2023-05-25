#include<iostream>
#include<algorithm>
using namespace std;
//#11052_카드 구매하기
int N, P[1001],dp[1001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> P[i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + P[j]);
	cout << dp[N];
}