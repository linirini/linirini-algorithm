#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#9251_LCS
string str1, str2;
int dp[1001][1001];
vector<char>LCS;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> str1 >> str2;
	str1 = '0' + str1;
	str2 = '0' + str2;
	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (str1[i] == str2[j])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[str1.length()-1][str2.length()-1]<<'\n';
	int i = str1.length()-1, j = str2.length()-1;
	while (1) {
		if (i == 0 || j == 0)break;
		if (dp[i][j] == dp[i][j - 1]) j --;
		else if (dp[i][j] == dp[i - 1][j]) i --;
		else {
			LCS.push_back(str1[i]);
			i--;
			j--;
		}
	}
	for (int i = LCS.size()-1; i >= 0; i--)cout << LCS[i];
}