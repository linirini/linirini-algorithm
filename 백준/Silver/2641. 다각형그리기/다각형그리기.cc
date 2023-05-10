#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//#2641_다각형그리기
int N, T, s[51],rev[51],flag;
vector<vector<int>>ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		if (s[i] == 1)rev[i] = 3;
		else if (s[i] == 2)rev[i] = 4;
		else if (s[i] == 3)rev[i] = 1;
		else rev[i] = 2;
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int>tmp(N);
		for (int j = 0; j < N; j++)cin >> tmp[j];
		for (int j = 0; j < N; j++) {
			flag = 1;
			for (int k = 0; k < N; k++) {
				if (s[k] != tmp[(int)(j + k) % N]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				ans.push_back(tmp);
				break;
			}
		}
		if (!flag) {
			for (int j = 0; j < N; j++) {
				flag = 1;
				for (int k = 0; k < N; k++) {
					if (rev[k] != tmp[N-1-(int)(j + k) % N]) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					ans.push_back(tmp);
					break;
				}
			}
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}