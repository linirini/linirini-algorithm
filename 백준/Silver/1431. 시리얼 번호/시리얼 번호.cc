#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#1431_시리얼 번호
int N;
string str[51];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	vector<pair<pair<int,int>,string>>v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		int sum = 0;
		for (int j = 0; j < str[i].length(); j++) {
			if (str[i][j] - '0' >= 0 && str[i][j] - '0' <= 9)sum += str[i][j] - '0';
		}
		v.push_back({ { str[i].length(),sum }, str[i]});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].second << '\n';
	}
}