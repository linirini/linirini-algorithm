#include<iostream>
#include<algorithm>
using namespace std;
//#23295_스터디 시간 정하기 1
long long N, T,K,visited[100001], cnt[100001], minTime=1e9,maxTime,ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			long long s, e;
			cin >> s >> e;
			visited[s] += 1;
			visited[e] -= 1;
			minTime = min(minTime, s);
			maxTime = max(maxTime, e);
		}
	}
	cnt[minTime] = visited[minTime];
	for (int i = minTime+1; i <= maxTime; i++) cnt[i] = cnt[i - 1] + visited[i];
	long long sum = 0,Max = 0;
	for(int i=minTime;i<= maxTime;i++) {
		if (i >= minTime+T)sum -= cnt[i - T];
		sum += cnt[i];
		if (Max < sum) {
			ans = i - T+1;
			Max = sum;
		}
	}
	cout << ans << ' ' << ans+T;
}