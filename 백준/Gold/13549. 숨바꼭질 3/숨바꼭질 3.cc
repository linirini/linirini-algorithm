#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
//#13549_숨바꼭질 3
int N, K, visited[100001];
deque<pair<int,int>>dq;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	dq.push_back({N,0});
	while (!dq.empty()) {
		int now = dq.front().first;
		int t = dq.front().second;
		dq.pop_front();
		visited[now] = 1;
		if (now == K) {
			cout << t;
			break;
		}
		if ((now * 2) <= 100000 && !visited[now * 2]) dq.push_front({now * 2, t});
		if ((now + 1) <= 100000 && !visited[now + 1]) dq.push_back({ now + 1,t + 1 });
		if ((now - 1) >= 0 && !visited[now - 1]) dq.push_back({ now - 1,t + 1 });
	}
}