#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//#13913_숨바꼭질 4
int N, K, parent[200001];
queue<int>q;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < 200001; i++)parent[i] = -1;
	q.push(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == K) break;
		if (now+1<=200000&& parent[now + 1] == -1) {
			parent[now + 1] = now;
			q.push(now + 1);
		}
		if (now*2 <= 200000&& parent[now * 2] == -1) {
			parent[now * 2] = now;
			q.push(now * 2);
		}
		if (now-1>=0&& parent[now - 1] == -1) {
			parent[now - 1] = now;
			q.push(now - 1);
		}
	}
	stack<int>path;
	while (K != N) {
		path.push(K);
		K = parent[K];
	}
	cout << path.size()<<'\n'<<N<<' ';
	while (!path.empty()) {
		cout << path.top() << ' ';
		path.pop();
	}
}