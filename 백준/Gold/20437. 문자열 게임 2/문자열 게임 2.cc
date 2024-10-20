#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#20437_문자열 게임 2
int T, K;
string W;
vector<int> alph[26];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 26; i++)alph[i].clear();
		int Min = 1e9, Max = 0;
		cin >> W >> K;
		for (int i = 0; i < W.length(); i++) alph[W[i] - 'a'].push_back(i);
		for (int i = 0; i < 26; i++) {
			if (alph[i].size() >= K) {
				for (int j = 0; j <= alph[i].size() - K; j++) {
					Min = min(Min, alph[i][j + K - 1] - alph[i][j] + 1);
					Max = max(Max, alph[i][j + K - 1] - alph[i][j] + 1);
				}
			}
		}
		if(Min==1e9|| Max==0)cout<<-1<<'\n';
		else cout << Min << ' ' << Max << '\n';
	}
}