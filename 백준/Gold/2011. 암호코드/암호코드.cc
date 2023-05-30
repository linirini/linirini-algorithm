#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#2011_암호코드
#define MOD 1000000
int c[5001],dp[5001];
string code;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> code;
	if (code == "0") {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < code.size(); i++)c[i+1] = code[i] - '0';
	dp[0] = 1;
	if (c[1] >= 1 && c[1] <= 9)dp[1] = 1;
	for (int i = 2; i <= code.size(); i++) {
		if (c[i] >= 1 && c[i] <= 9)dp[i] = (dp[i - 1] + dp[i]) % MOD;
		int tmp = c[i] + c[i - 1] * 10;
		if (tmp >= 10 && tmp <= 26)dp[i] = (dp[i - 2] + dp[i]) % MOD;
	}
	cout<<dp[code.size()];
}