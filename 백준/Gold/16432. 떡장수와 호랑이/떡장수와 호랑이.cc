#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
#include<math.h>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#16432_떡장수와 호랑이
int N, m, a, vis[1001][10];
vector<int>arr[1001];
vector<int>ans;
void go(int day,int now,string str) {
	if (day == N) {
		for (int i = 0; i < str.size();i++) {
			cout << str[i] << '\n';
		}
		exit(0);
	}
	for (auto next : arr[day+1]) {
		if (vis[day+1][next]|| now==next)continue;
		vis[day + 1][next] = 1;
		go(day + 1, next,str+to_string(next));
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> m;
		for (int j= 0; j < m; j++) {
			cin >> a;
			arr[i].push_back(a);
		}
	}
	for (auto i:arr[1]) {
		vis[1][i] = 1;
		go(1,i,to_string(i));
	}
	cout<< -1;
}