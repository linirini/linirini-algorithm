#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
//#2493_탑
stack<pair<int,int>> s;
int N, n, count;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> n;
		while (!s.empty()) {
			if (n < s.top().second) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty())cout << 0 << ' ';
		s.push({ i + 1,n });
	}
}