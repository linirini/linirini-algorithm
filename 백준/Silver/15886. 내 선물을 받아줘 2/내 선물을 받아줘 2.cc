#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#15886_내 선물을 받아줘 2
int N, cnt;
string str;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> str;
	char pre = str[0];
	if (str[0] == 'W')cnt++;
	for (int i = 1; i < N; i++) {
		if (pre == 'E' && str[i] == 'W')cnt++;
		pre = str[i];
	}
	cout << cnt;
}