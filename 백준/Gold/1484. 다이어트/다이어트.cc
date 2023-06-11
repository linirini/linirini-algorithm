#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#1484_다이어트
long long G,flag;
vector<long long>power;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> G;
	int st = 1, en = 2;
	while (st < en) {
		if (en * en - st * st > G)st++;
		else if (en * en - st * st < G)en++;
		else {
			flag = 1;
			cout << en << '\n';
			en++;
		}
	}
	if(!flag) cout << -1;
}