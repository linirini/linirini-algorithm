#include<iostream>
#include<algorithm>
#include<string>
#include<climits>

using namespace std;
//#3687_성냥개비
const long long MAX = LLONG_MAX;
int t, n;
long long minNum[8] = { 0,0,1,7,4,2,0,8 };
long long dp[101];
void goMax(int x) {
	string str = "";
	if (x % 2) {
		cout << "7";
		x -= 3;
	}
	for (int i = 0; i < x/2 ; i++) cout<<"1";
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	fill(dp,dp+101,MAX);
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;
	for(int i=8;i<=100;i++)
		for (int j = 2; j <= 7; j++)
 			if(i-j>=2)dp[i] = min(dp[i], dp[i - j] * 10 + minNum[j]);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << ' ';
		goMax(n);
	}
}