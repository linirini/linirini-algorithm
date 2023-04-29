#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#1043_거짓말
int N, M, n, stu,truth[51], par[51];
vector<int>party[51],know;
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) par[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	int ans = M;
	cin >> n;
	for (int i = 0; i <= N; i++)par[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> stu;
		truth[stu] = 1;
		know.push_back(stu);
	}
	for (int i = 1; i <= M; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> stu;
			party[i].push_back(stu);
		}
	}
	for(int i=1;i<=M;i++){
		int a = party[i][0];
		for (int j = 1; j < party[i].size(); j++) merge(a,party[i][j]);
	}
	for (int i = 0; i < know.size(); i++)truth[find(know[i])] = 1;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (truth[find(party[i][j])]) {
				ans--;
				break;
			}
		}
	}
	cout << ans;
}