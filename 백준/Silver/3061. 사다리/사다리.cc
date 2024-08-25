#include<iostream>
#include<algorithm>
using namespace std;
//#3061_사다리
int T, N;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int ans = 0;
		int arr[1001] = { 0, };
		int idx[1001] = { 0, };
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			idx[arr[i]] = i;
		}
		for (int i = 1; i <= N; i++) {
			int tmp = idx[i];

			for (int j = tmp; j > i; j--) {
				swap(arr[j], arr[j - 1]);
				idx[arr[j]] = j;
				idx[arr[j - 1]] = j - 1;
				ans++;
			}
		}
		cout << ans<<'\n';
	}
}
