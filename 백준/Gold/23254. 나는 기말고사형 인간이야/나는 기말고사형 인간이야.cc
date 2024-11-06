#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#23254_나는 기말고사형 인간이야
int N, M, ans;
pair<int, int>ba[200001];
priority_queue<pair<int, int>>pq;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	N *= 24;
	for (int i = 0; i < M; i++)cin >> ba[i].second;
	for (int i = 0; i < M; i++)cin >> ba[i].first;
	for (int i = 0; i < M; i++)pq.push(ba[i]);
	while(N>0 && !pq.empty()){
		pair<int,int> now = pq.top();
		pq.pop();
		int need = (100 - now.second) / now.first;
		if (need <= N) {
			now.second += now.first*need;
			N -= need;
			if (now.second < 100) {
				now.first = 100 - now.second;
				pq.push(now);
			}
			else ans += now.second;
		}
		else if (need > N) {
			now.second += now.first * N;
			ans += now.second;
			N -= N;
		}
	}
	while (!pq.empty()) {
		ans += pq.top().second;
		pq.pop();
	}
	cout << ans;
} 