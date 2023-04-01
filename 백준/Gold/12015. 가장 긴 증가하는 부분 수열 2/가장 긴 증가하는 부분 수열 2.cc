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
//#12015_가장 긴 증가하는 부분 수열 2
int N, A[10000011];
vector<int>v;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	v.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		if (v.back() < A[i])v.push_back(A[i]);
		else {
			auto it = lower_bound(v.begin(), v.end(), A[i]);
			*it = A[i];
		}
	}
	cout << v.size();
}