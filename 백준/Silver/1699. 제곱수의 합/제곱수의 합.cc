#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#1699_제곱수의 합
int N,dp[100001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j <= sqrt(i); j++) {
			dp[i] = min(dp[i], dp[i - j * j]+1);
		}
	}
	cout << dp[N];
}