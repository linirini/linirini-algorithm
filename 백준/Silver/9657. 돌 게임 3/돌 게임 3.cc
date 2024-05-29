#include<iostream>
#include<algorithm>
using namespace std;
//#9657_돌 게임 3
int N, dp[1001], pick[3] = { 1,3,4 };
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= N; i++) {
		int flag = 0;
		for (int j = 0; j < 3; j++) {
			if (!dp[i - pick[j]])flag = 1;
		}
		dp[i] = flag;
	}
	dp[N] ? cout << "SK" : cout << "CY";
}