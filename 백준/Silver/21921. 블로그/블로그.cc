#include<iostream>
#include<algorithm>
using namespace std;
//#21921_블로그
int N, X,visitors[250001],Max,cnt,sum;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> X;
	for (int i = 1; i <= N; i++)cin >> visitors[i];
	for (int i = 1; i <= N; i++) {
		if (i >= X)sum -= visitors[i-X];
		sum += visitors[i];
		if (Max < sum) {
			Max = sum;
			cnt = 1;
		}
		else if (Max == sum)cnt++;
	}
	!Max?cout<<"SAD":cout << Max << '\n' << cnt;
}