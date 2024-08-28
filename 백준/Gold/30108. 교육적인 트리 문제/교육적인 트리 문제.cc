#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#30108_교육적인 트리 문제
long long N, n, ans;
priority_queue<long long> A;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) cin >> n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		A.push(n);
	}
	while (!A.empty()) {
		ans += A.top();
		A.pop();
		cout << ans << '\n';
	}
}