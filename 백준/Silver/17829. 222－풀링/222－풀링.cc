#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
//#17829_222-풀링
int N, board[1050][1050],ans;
int find(int x, int y, int range) {
	if (range == 2) {
		priority_queue<int>pq;
		for (int i = x; i < x + 2; i++)
			for (int j = y; j < y + 2; j++)
				pq.push(board[i][j]);
		pq.pop();
		return pq.top();
	}
	range /= 2;
	priority_queue<int>pq;
	pq.push(find(x, y, range));
	pq.push(find(x+range,y,range));
	pq.push(find(x, y + range, range));
	pq.push(find(x + range, y + range, range));
	pq.pop();
	return pq.top();
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	cout << find(0, 0, N);
}