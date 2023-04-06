#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#1038_감소하는 수
int N;
vector<long long> ans;
void go(long long num) {
	ans.push_back(num);
	long long last = num % 10;
	if (last == 0)return;
	for (int i = last - 1; i >= 0; i--) {
		long long newNum = num * 10 + i;
		go(newNum);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	if (N < 10)cout << N;
	else {
		for (int i = 0; i < 10; i++) {
			go(i);
		}
		sort(ans.begin(), ans.end());
		if (ans.size() <= N)cout << -1;
		else cout << ans[N];
	}
}