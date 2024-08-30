#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
//#25381_ABBC
int ans,visited[300001];
string S;
queue<int>q;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'B')q.push(i);
		else if (S[i] == 'C' && !q.empty()) {
			visited[q.front()] = 1;
			q.pop();
			ans++;
		}
	}
	int a_cnt = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'A')a_cnt++;
		else if (S[i] == 'B' && a_cnt && !visited[i]) {
			visited[i] = 1;
			a_cnt--;
			ans++;
		}
	}
	cout << ans;
}