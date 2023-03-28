#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#13306_트리
int N, Q,parent[200001],x,b,c,d,parInput[200001];
vector<string> ans;
struct cmd{
	int x;
	int y;
	int z;
};
vector<cmd> arr;
int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 2; i <= N; i++)cin >> parInput[i];
	for (int i = 0; i < N - 1 + Q; i++) {
		cin >> x;
		if (x == 1) {
			cin >> c >> d;
			arr.push_back({ x,c,d });
		}
		else {
			cin >> b;
			arr.push_back({ x,b,0 });
		}
	}
	for (int i = N-2+Q; i >= 0; i--) {
		if (arr[i].x == 1) {
			if (find(arr[i].y) == find(arr[i].z))ans.push_back("YES");
			else ans.push_back("NO");
		}
		else {
			merge(arr[i].y, parInput[arr[i].y]);
		}
	}
	for (int i = Q-1; i >= 0; i--)cout << ans[i] << '\n';
}
