#include<iostream>
#include<algorithm>
using namespace std;
//#21758_꿀 따기
int N, ggul[100001], sum[100001], ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ggul[i];
		sum[i] = sum[i - 1] + ggul[i];
	}
	for (int i = 2; i < N; i++) 
		ans = max(ans, sum[N] - ggul[1] - ggul[i] + sum[N] - sum[i]);
	for (int i = 2; i < N; i++)
		ans = max(ans, sum[N] - ggul[N] - ggul[i] + sum[i-1]);
	for (int i = 2; i < N; i++)
		ans = max(ans, sum[i] - ggul[1] + sum[N] - sum[i - 1] - ggul[N]);
	cout << ans;
}
