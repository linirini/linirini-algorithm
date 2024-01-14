#include<iostream>
#include<algorithm>
using namespace std;
//#23252_블록
int T, A, B, C;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> A >> B >> C;
		if (C > A) {
			cout << "No\n";
			continue;
		}
		if ((B%2)&&A)B--;
		A -= C;
		C = 0;
		!(A%2)&&!(B%2) ? cout << "Yes\n" : cout << "No\n";
	}
}