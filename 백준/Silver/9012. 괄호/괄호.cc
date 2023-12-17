#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#4153_직각삼각형
int T;
int main() {
	cin >> T;
	while (T--) {
		string str;
		int cnt1 = 0, cnt2 = 0;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') cnt1++;
			else if(str[i]==')') cnt2++;
			if (cnt2 > cnt1)break;
		}
		cnt1 == cnt2 ? cout << "YES" << '\n' : cout << "NO" << '\n';
	}
}