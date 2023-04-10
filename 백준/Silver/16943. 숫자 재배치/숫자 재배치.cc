#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#16943_숫자 재배치
int A, B;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> A >> B;
	int prev = 0;
	while (A > 0) {
		v.push_back(A % 10);
		A /= 10;
	}
	sort(v.begin(), v.end());
	do{
		int pos = 0;
		if (v[0] != 0) {
			for (int i = 0; i < v.size(); i++) {
				pos *= 10;
				pos += v[i];
			}
			
			if (pos > prev && pos < B)prev = pos;
		}
	}while (next_permutation(v.begin(), v.end()));
	!prev ? cout << -1 : cout << prev;
}