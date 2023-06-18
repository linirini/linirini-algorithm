#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#1195_킥다운
int ans = 1e9;
string g1, g2;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> g1 >> g2;
	int ans = g1.length() + g2.length();
	if (g1.length() > g2.length())swap(g1, g2);
	for (int i = 0; i < g1.length(); i++) {
		int len = g1.length(), flag = 0;
		for (int j = 0; j <= i; j++)
			if (g2[j] == '2' && g1[len - 1 - i + j] == '2') {
				flag = 1;
				break;
			}
		if (!flag)ans = min(ans, (int)g1.length() + (int)g2.length() - 1 - i);
	}
	for (int i = 0; i < g1.length(); i++) {
		int len = g2.length(), flag = 0;
		for (int j = 0; j <= i; j++)
			if (g1[j] == '2' && g2[len-1-i+j] == '2') {
				flag = 1;
				break;
			}
		if (!flag)ans = min(ans, (int)g1.length() + (int)g2.length() - 1 - i);
	}
	for (int i = 0; i < g2.length() - g1.length(); i++) {
		int flag = 0;
		for(int j=0;j<g1.length();j++)
			if (g1[j] == '2' && g2[i + j] == '2') {
				flag = 1;
				break;
			}
		if (!flag)ans = min(ans, (int)g2.length());
	}
	cout << ans;
}