#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#11585_속타는 저녁 메뉴
string T, P;
char C;
vector<int>failure;
int N,cnt;
int gcd(int a, int b) {
	if (!b)return a;
	return gcd(b, a % b);
}
void kmp() {
	int j = 0;
	for (int i = 0; i < T.size()-1; i++) {
		while (j > 0 && T[i] != P[j]) j = failure[j - 1];
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				cnt++;
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> C;
		T += C;
	}
	T = T + T;
	for (int i = 0; i < N; i++) {
		cin >> C;
		P += C;
	}
	failure.resize(P.size());
	fail();
	kmp();
	int div = gcd(N,cnt);
	if (div > 1) {
		cnt /= div;
		N /= div;
	}
	cout << cnt <<'/'<<N;
}