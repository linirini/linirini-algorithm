#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#3356_라디오 전송
int L;
string S;
vector<int> failure;
void fail() {
	int j = 0;
	for (int i = 1; i < S.size(); i++) {
		while (j > 0 && S[i] != S[j])
			j = failure[j - 1];
		if (S[i] == S[j]) {
			failure[i] = j + 1;
			j++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> L >> S;
	failure.resize(S.size());
	fail();
	cout << L - failure[L - 1];
}