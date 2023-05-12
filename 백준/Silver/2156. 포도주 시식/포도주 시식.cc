#include<iostream>
#include<algorithm>
using namespace std;
//#2156_포도주 시식
int n, wine[10001], dp[10001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> wine[i];
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++) dp[i] = max(dp[i-1],max(dp[i - 3] + wine[i - 1], dp[i - 2]) + wine[i]);
	cout << dp[n];
}