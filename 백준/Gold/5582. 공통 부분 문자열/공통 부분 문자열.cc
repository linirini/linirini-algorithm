#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#5582_공통 부분 문자열
int dp[4001][4001], ans;
string s, t;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < t.length(); j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				ans = max(ans, dp[i + 1][j + 1]);
			}
		}
	}
	cout << ans;
}