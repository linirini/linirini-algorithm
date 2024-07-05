#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#15831_준표의 조약돌
int N, B, W, ans;
string stone;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> B >> W;
	cin >> stone;
	int st = 0, en = 0, bcnt = 0, wcnt = 0;
	stone[st] == 'B' ? bcnt = 1 : wcnt = 1;
	while (en<N) {
		if(wcnt>=W && bcnt<=B) ans = max(ans, en - st + 1);
		if (bcnt > B) stone[st++]=='B'?bcnt--:wcnt--;
		else stone[++en] == 'B' ? bcnt++ : wcnt++;
	}
	cout << ans;
}