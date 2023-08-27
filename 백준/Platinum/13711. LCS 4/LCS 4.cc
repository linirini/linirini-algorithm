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
//#13711_LCS 4
int N, se[100001],ans[100001];
vector<int>v;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		se[a] = i;
	}
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		ans[i] = se[b];
	}
	v.push_back(ans[0]);
	for (int i = 1; i < N; i++) {
		if (v.back() < ans[i])v.push_back(ans[i]);
		else {
			auto it = lower_bound(v.begin(), v.end(), ans[i]);
			*it = ans[i];
		}
	}
	cout << v.size();

}