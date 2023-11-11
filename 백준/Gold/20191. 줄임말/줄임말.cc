#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#20191_줄임말
string S, T;
vector<int>alph[26];
int visited[26];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> S >> T;
	for (int i = 0; i < T.size(); i++) {
		alph[T[i] - 'a'].push_back(i);
		visited[T[i] - 'a'] = 1;
	}
	for (int i = 0; i < S.size(); i++)
		if (!visited[S[i]-'a']) {
			cout << -1;
			return 0;
		}
	int pos = -1, cnt = 1;
	for (int i = 0; i < S.size(); i++) {
		auto it = lower_bound(alph[S[i] - 'a'].begin(), alph[S[i] - 'a'].end(), pos + 1);
		if (it == alph[S[i]-'a'].end())cnt++, it = alph[S[i]-'a'].begin();
		pos = *it;
	}
	cout << cnt;
}