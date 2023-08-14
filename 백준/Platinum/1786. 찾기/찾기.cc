#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#1786_찾기
string T, P;
vector<int>ans,failure;
int cnt;
void kmp() {
	int j = 0;
	for (int i = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != P[j]) j = failure[j - 1];
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				cnt++;
				ans.push_back(i - P.size() + 2);
				j = failure[j];
			}
			else j++;
		}
	}
}
void fail() {
	int j = 0;
	for (int i = 1; i < P.size(); i++) {
		while (j > 0 && P[i] != P[j])
			j = failure[j - 1];
		if (P[i] == P[j]) {
			failure[i] = j + 1;
			j++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	getline(cin, T);
	getline(cin, P);
	failure.resize(P.size());
	fail();
	kmp();
	cout << cnt << '\n';
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
}