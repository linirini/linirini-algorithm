#include<iostream>
#include<algorithm>
using namespace std;
//#29285_체육은 코딩과목 입니다
int ans = 0, t;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	for (int i = 0; i < 10; i++) {
		cin >> t;
		ans = (ans + t)% 4;
	}
	if (ans == 0)cout << 'N';
	if (ans == 1)cout << 'E';
	if (ans == 2)cout << 'S';
	if (ans == 3)cout << 'W';
}