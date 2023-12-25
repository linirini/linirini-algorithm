#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#23082_균형 삼진법
int N,flag;
string ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	if (!N) {
		cout << 0;
		return 0;
	}
	if(N < 0)flag = 1,N=-N;
	while (N > 0) {
		if (N % 3 == 1) {
			ans = flag ? 'T' + ans : '1' + ans;
			N /= 3;
		}
		else if (N % 3 == 0) {
			ans = '0' + ans;
			N /= 3;
		}
		else if (N % 3 == 2) {
			ans = flag ? '1' + ans : 'T' + ans;
			N = N / 3 + 1;
		}
	}
	cout << ans;
}