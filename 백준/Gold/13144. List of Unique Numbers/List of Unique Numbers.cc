#include<iostream>
#include<algorithm>
using namespace std;
//#13144_List of Unique Numbers
long long N,A[100001], visited[100001],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	int st = 0, en = 0;
	while (st<N) {
		while (!visited[A[en]]&&en<N) {
			visited[A[en]] = 1;
			en++;
		}	
		ans += (en - st);
		visited[A[st++]] = 0;
	}
	cout << ans;
}