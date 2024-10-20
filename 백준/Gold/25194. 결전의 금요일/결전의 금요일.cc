#include<iostream>
#include<algorithm>
using namespace std;
//#25194_결전의 금요일
int N, visited[7],ans;
void go(int sum) {
	if (ans)return;
	if (sum % 7 == 4) {
		ans = 1;
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (!visited[i])continue;
		visited[i]--;
		go(sum + i);
		visited[i]++;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if(x % 7) visited[x % 7]++;
	}
	go(0);
	ans ? cout << "YES" : cout << "NO";
}