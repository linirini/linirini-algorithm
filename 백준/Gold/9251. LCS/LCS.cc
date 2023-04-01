#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#9251_LCS
string str1, str2;
int dp[1001][1001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> str1 >> str2;
	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (str1[i - 1] == str2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[str1.length()][str2.length()];
}