#include<iostream>
#include<algorithm>
using namespace std;
//#29718_줄줄이 박수
int N, M, Q[2001], A, sum, ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			Q[j] += n;
		}
	cin >> A;
	for (int i = 0; i < M; i++) {
		sum += Q[i];
		if (i >= A)sum -= Q[i-A];
		ans = max(ans, sum);
	}
	cout << ans;
}