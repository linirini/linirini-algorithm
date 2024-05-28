#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#15903_카드 합체 놀이
long long n, m,ans;
priority_queue<long long, vector<long long>, greater<>>pq;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	while (m--) {
		long long firstCard = pq.top();
		pq.pop();
		long long secondCard = pq.top();
		pq.pop();
		long long sum = firstCard + secondCard;
		pq.push(sum);
		pq.push(sum);
	}
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
}