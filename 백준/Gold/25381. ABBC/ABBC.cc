#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
//#25381_ABBC
int ans;
string S;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> S;
	int b_cnt = 0, c_cnt = 0;
	for (int i = S.length()-1; i >= 0; i--) {
		if (S[i] == 'A') {
			if (b_cnt > 0) {
				ans++;
				b_cnt--;
			}
		}
		if (S[i] == 'B') {
			if (c_cnt > 0) {
				ans++;
				c_cnt--;
			}
			else b_cnt++;
		}
		if (S[i] == 'C') c_cnt++;
	}
	cout << ans;
}