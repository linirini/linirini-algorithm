#include<algorithm>
#include<iostream>
using namespace std;
int N, K, cost[100001],ans=0;
//#25603_짱해커 이동식
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> cost[i];
	int pos = 0;
	while (pos+K <= N) {
		int tmp = 1e9;
		int tmpPos = pos;
		for (int i = pos; i < pos + K && i < N; i++) {
			if (cost[i] <= tmp) {
				tmpPos = i;
				tmp = cost[i];
			}
		}
		pos = tmpPos+1;
		ans = max(tmp, ans);
	}
	cout << ans;
}