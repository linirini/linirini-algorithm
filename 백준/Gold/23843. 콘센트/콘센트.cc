#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
//#23843_콘센트
int N, M, t[10001];
priority_queue<int,vector<int>,greater<int>>pq;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> t[i];
	sort(t, t + N);
	reverse(t, t + N);
	for (int i = 0; i < (N, M); i++) pq.push(t[i]);
	for (int i = M; i < N; i++) {
		int top = pq.top();
		pq.pop();
		pq.push(t[i] + top);
	}
	while (pq.size() != 1)pq.pop();
	cout << pq.top();
}