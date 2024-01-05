#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
//#6198_옥상 정원 꾸미기
long long N, h,ans;
stack<int>s;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h;
		while (!s.empty()&&s.top() <= h) {
			s.pop();
			ans += s.size();
		}
		s.push(h);
	}
	while (!s.empty()) {
		s.pop();
		ans += s.size();
	}
	cout << ans;
}