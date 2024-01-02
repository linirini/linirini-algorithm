#include<iostream>
#include<algorithm>
using namespace std;
//#1806_부분합
long long N, S, num[100001],ans=1e9;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		num[i] = num[i - 1] + x;
	}
	long long st = 1, en = 1;
	while (en <= N) {
		if (num[en] - num[st - 1] >= S) {
			ans = min(ans, en - st + 1);
			st++;
		}
		else if (num[en] - num[st - 1] < S) en++;
	}
	ans==1e9?cout<<0:cout << ans;
}