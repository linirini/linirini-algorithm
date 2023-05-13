#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#2107_IPv6
string str;
vector<string>ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> str;
	int idx = 0, st = 0;
	string tmp = "";
	while(idx<str.length()) {
		while (str[idx] != ':'&&idx<str.length()) {
			tmp = tmp + str[idx];
			idx++;
		}
		while(tmp.length()<4) tmp = '0' + tmp;
		ans.push_back(tmp);
		tmp = "";
		if (str[idx] == ':' && str[idx + 1] == ':') {
			st = ans.size();
			idx += 2;
		}
		else idx++;
	}
	if (ans.size() == 8) {
		for (int i = 0; i < ans.size(); i++) {
			if(i==ans.size()-1)cout << ans[ans.size() - 1];
			else cout << ans[i] << ':';
		}
	}
	else {
		for (int i = 0; i < st; i++)cout << ans[i] << ':';
		for (int i = 0; i < 8 - ans.size(); i++) {
			if (st+i == 7)cout << "0000";
			else cout << "0000:";
		}
		for (int i = st; i < ans.size(); i++) {
			if (i == ans.size() - 1)cout << ans[ans.size() - 1];
			else cout << ans[i] << ':';
		}
	}
}