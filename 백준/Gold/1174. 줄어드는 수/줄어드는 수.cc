#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#1174_줄어드는 수
int N,visited[11];
vector<long long> ans,num;
void go(int now, int cnt, int idx) {
	if (now == cnt) {
		long long sum = 0;
		for (int i = 0; i < num.size(); i++) {
			sum += num[i];
			sum *= 10;
		}
		sum /= 10;
		ans.push_back(sum);
		return;
	}
	for (int i = idx; i < 10; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			num.push_back(9-i);
			go(now, cnt + 1, i + 1);
			num.pop_back();
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	if (N > 1023) {
		cout << -1;
		return 0;
	}
	for(int i=1;i<=10;i++) go(i,0,0);
	sort(ans.begin(), ans.end());
	cout << ans[N - 1];
}
