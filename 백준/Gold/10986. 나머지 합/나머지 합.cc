#include<iostream>
#include<algorithm>
using namespace std;
//#10986_나머지 합
long long N, M, A[1000001], modSum[1001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		A[i] = A[i - 1] + n;
		modSum[A[i] % M]++;
	}
	long long ans = modSum[0];
	for (int i = 0; i < M; i++) {
		ans += (modSum[i] * (modSum[i] - 1)) / 2;
	}
	cout << ans;
}