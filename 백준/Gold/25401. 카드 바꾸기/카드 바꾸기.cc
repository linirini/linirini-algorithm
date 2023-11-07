#include<iostream>
#include<algorithm>
using namespace std;
//#25401_카드 바꾸기
int N, card[501], ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> card[i];
	ans = N - 2;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (abs(card[j] - card[i]) % (j - i) == 0) {
				int d = (card[j] - card[i]) / (j - i), cnt = 0;
				for (int k = 0; k < N; k++) 
					if (card[k] != card[i] + (k - i) * d) cnt++;
				ans = min(ans, cnt);
			}
		}
	}
	cout << ans;
}