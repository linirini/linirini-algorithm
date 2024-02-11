#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#6443_애너그램
int N, alph[26];
string str;
char anagram[1001];
void go(int idx, int cnt) {
	if (cnt == str.length()) {
		cout << anagram << '\n';
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (alph[i]>0) {
			alph[i]--;
			anagram[cnt] = i + 'a';
			go(i,cnt+1);
			alph[i]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> str;
		for (int i = 0; i < 26; i++)alph[i] = 0;
		for (int i = 0; i < str.length(); i++)alph[str[i] - 'a']++;
		go(0, 0);
	}
}