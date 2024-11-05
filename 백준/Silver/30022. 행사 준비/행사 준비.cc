#include<iostream>
#include<algorithm>
using namespace std;
//#30022_행사 준비
long long N, A, B, ans;
pair<long long, long long> product[100001];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
	return (a.first - a.second) < (b.first - b.second);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) cin >> product[i].first >> product[i].second;
	sort(product, product + N, cmp);
	for (int i = 0; i < A; i++)ans += product[i].first;
	for (int i = A; i < N; i++)ans += product[i].second;
	cout << ans;
}