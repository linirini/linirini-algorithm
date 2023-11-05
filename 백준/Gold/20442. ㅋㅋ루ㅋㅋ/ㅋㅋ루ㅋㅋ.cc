#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#20442_ㅋㅋ루ㅋㅋ
string str;
int leftKCnt[3000001], rightKCnt[3000001], kcnt,ans;
vector<int>r;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'K') kcnt++;
		else {
			r.push_back(i);
			leftKCnt[i] = kcnt;
		}
	}
	kcnt = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'K') kcnt++;
		else rightKCnt[i] = kcnt;
	}
	int st = 0, en = r.size() - 1;
	while (st <= en) {
		int kcnt1 = leftKCnt[r[st]];
		int kcnt2 = rightKCnt[r[en]];
		ans = max(ans, en - st + 1 + (min(kcnt1, kcnt2) * 2));
		if (kcnt1 > kcnt2)en--;
		else st++;
	}
	cout << ans;
}