#include<iostream>
#include<algorithm>
using namespace std;
//#22862_가장 긴 짝수 연속한 부분 수열
int N, K, S[1000001],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int num = 0;
		cin >> num;
		S[i] = num % 2 ? 1 : 0;
		S[i] = S[i - 1] + S[i];
	}
	int st = 1, en = 1;
	while (en <= N) {
		if (S[en] - S[st - 1] <= K) {
			ans = max(ans, (en - st +1) - (S[en]-S[st-1]));
			en++;
		}
		else if (S[en] - S[st - 1] > K)st++;
	}
	cout << ans;
}