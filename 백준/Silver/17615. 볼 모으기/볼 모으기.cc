#include<iostream>
#include<algorithm>
using namespace std;
//#17615_볼 모으기
int N,Rcnt,Bcnt,ans=1e9;
string str;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N>>str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R')Rcnt++;
	}
	Bcnt = N - Rcnt;
	if (N == 1||Bcnt == N || Rcnt == N) {
		cout << 0;
		return 0;
	}
	char prev = str[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (prev == str[i])cnt++;
		else {
			if (str[0] == 'R')ans = min(Bcnt, Rcnt - cnt);
			else ans = min(Bcnt - cnt, Rcnt);
			break;
		}
	}
	prev = str[N - 1];
	cnt = 1;
	for (int i = N-2; i >=0; i--) {
		if (prev == str[i])cnt++;
		else {
			if (str[N-1] == 'R')ans = min(Bcnt, Rcnt - cnt);
			else ans = min(Bcnt - cnt, Rcnt);
			break;
		}
	}
	cout << ans;
}