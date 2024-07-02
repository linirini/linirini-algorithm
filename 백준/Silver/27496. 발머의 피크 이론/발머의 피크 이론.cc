#include<iostream>
#include<algorithm>
using namespace std;
//#27496_발머의 피크 이론
int N, L, a[1000001], sum, ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
		if (i >= L)sum -= a[i - L];
		if (sum >= 129 && sum <= 138)ans++;
	}
	cout << ans;
}