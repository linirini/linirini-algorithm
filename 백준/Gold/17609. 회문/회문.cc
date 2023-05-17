#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#17609_회문
int T, ans;
string str;
void palindrome(int st, int en, int cnt) {
	if (cnt > 1)return;
	if (st >= en) {
		ans = min(cnt,ans);
		return;
	}
	if (str[st] == str[en]) palindrome(st+1, en-1, cnt);
	else if (str[st] != str[en]) {
		palindrome(st + 1, en, cnt + 1);
		palindrome(st, en - 1, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 100001;
		str="";
		cin >> str;
		palindrome(0,str.length()-1,0);
		if (ans <= 1)cout << ans << '\n';
		else cout << 2 << '\n';
	}
}