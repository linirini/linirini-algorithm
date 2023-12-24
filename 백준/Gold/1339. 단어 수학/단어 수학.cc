#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#1339_단어 수학
int N,alph[26],ans;
bool cmp(int a, int b) {return a > b;}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		int pos = 1;
		cin >> str;
		for (int j = str.length() - 1; j >= 0; j--) {
			alph[str[j] - 'A'] += pos;
			pos *= 10;
		}
	}
	sort(alph, alph + 26, cmp);
	for (int i = 0; i < 10; i++) ans += alph[i] * (9 - i);
	cout << ans;
}