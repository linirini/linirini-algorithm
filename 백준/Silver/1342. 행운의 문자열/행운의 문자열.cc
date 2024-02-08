#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#1342_행운의 문자열
string S;
int alph[26], ans;
void go(int idx, string cur) {
	if (idx == S.size()) {
		ans++;
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (!alph[i]) continue;
		if (cur != "" && cur[cur.size() - 1] == (char)('a' + i)) continue;
		alph[i]--;
		go(idx + 1, cur + (char)('a' + i));
		alph[i]++;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
		alph[S[i] - 'a']++;
	go(0, "");
	cout << ans;
}