#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#13422_도둑
int T, N, M, K;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		vector<int> v;
		cin >> N >> M >> K;
		v.resize(N + 1);
		for (int i = 0; i < N; i++)cin >> v[i];
		int sum=0,cnt=0;
		for (int i = 0; i < M; i++)sum += v[i];
		if (sum < K)cnt++;
		if (N != M) {
			for (int i = 1; i < N; i++) {
				sum -= v[i - 1];
				sum += v[(i + M - 1) % N];
				if (sum < K)cnt++;
			}
		}
		cout << cnt << '\n';
	}
}