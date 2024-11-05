#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#31797_아~파트 아파트
int N, M, ans;
vector<pair<int, int>>hands;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int left, right;
		cin >> left >> right;
		hands.push_back({ left,i+1 });
		hands.push_back({ right,i+1 });
	}
	sort(hands.begin(), hands.end());
	int idx = N % (M * 2) == 0 ? M * 2 : N % (M * 2);
	cout << hands[idx-1].second;
}