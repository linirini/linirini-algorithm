#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
//#17952_과제는 끝나지 않아
int N,x,y, com, ans;
stack<pair<int,int>>s;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> com;
		if (com) {
			cin >> x >> y;
			s.push({ x, y });
		}
		if (!s.empty()) {
			s.top().second--;
			if (s.top().second == 0) {
				ans += s.top().first;
				s.pop();
			}
		}
	}
	cout << ans;
}