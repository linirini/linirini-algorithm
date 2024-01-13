#include<iostream>
#include<algorithm>
using namespace std;
//#4781_사탕 가게
int dp[10001];
struct Candy {
	int C;
	int P;
};
Candy c[5001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	while (true) {
		int n;
		double m;
		cin >> n >> m;
		if (n == 0 && m == 0.00)break;
		int M = m * 100.0 + 0.5;
		for (int i = 1; i <= M; i++) dp[i] = 0;
		for (int i = 1; i <= n; i++) {
			double p;
			cin >> c[i].C >> p;
			c[i].P = p*100.0+0.5;
		}
		for (int i = 1; i <= n; i++)
			for (int j = c[i].P; j <= M; j++) 
				dp[j] = max(dp[j], dp[j - c[i].P] + c[i].C);
		cout << dp[M] << '\n';
	}
}