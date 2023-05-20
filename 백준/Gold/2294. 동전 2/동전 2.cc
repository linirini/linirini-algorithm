#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
//#2294_동전 2
int n, k, coin[101], dp[100001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i <= k; i++)dp[i] = 1e9;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) 
		for (int j = coin[i]; j <= k; j++) 
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	if (dp[k] == 1e9)cout << -1;
	else cout<<dp[k];
}