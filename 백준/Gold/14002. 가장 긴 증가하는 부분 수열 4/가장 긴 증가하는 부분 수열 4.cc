#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#14002_가장 긴 증가하는 부분 수열 4
vector <int> V, ans;
int N, A[1001], dp[10001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		int cnt = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
		if (cnt == V.size()) V.push_back(A[i]);
		else V[cnt] = A[i];
		dp[i] = cnt;
	}
	int Max = 0;
	for (int i = 1; i <= N; i++) Max = max(dp[i], Max);
	for (int i = N; i > 0; i--)
		if (dp[i] == Max) ans.push_back(A[i]), Max--;
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int n : ans) cout << n << ' ';
}
