#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#1697_숨바꼭질
int N, K,visited[200001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K; 
	queue<int>q;
	q.push(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == K) {
			cout << visited[K];
			break;
		}
		if ((now + 1) >= 0 && (now + 1) <= 200000 &&!visited[now + 1]) {
			q.push(now + 1);
			visited[now + 1] = visited[now] + 1;
		}
		if ((now - 1) >= 0 && (now - 1) <= 200000 &&!visited[now - 1]) {
			q.push(now - 1);
			visited[now - 1] = visited[now] + 1;
		}
		if ((now * 2) >= 0 && (now * 2) <= 200000 && !visited[now * 2]) {
			q.push(now * 2);
			visited[now * 2] = visited[now] + 1;
		}
	}
}
