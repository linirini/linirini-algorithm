#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#2075_N번째 큰 수
int N;
priority_queue<int,vector<int>,greater<int>>pq;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N*N; i++) {
		int n;
		cin >> n;
		pq.push(n);
		if (pq.size() > N)pq.pop();
	}
	cout << pq.top();
}