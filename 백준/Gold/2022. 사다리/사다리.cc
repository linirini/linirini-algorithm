#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#2022_사다리
double x, y, c, ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> x >> y >> c;
	double left = 0, right = min(x,y);
	while (right - left >= 0.0001) {
		ans = (left + right) / 2;
		double h1 = sqrt(pow(x, 2) - pow(ans, 2));
		double h2 = sqrt(pow(y, 2) - pow(ans, 2));
		double result = (h1 * h2) / (h1 + h2);
		if (result >= c)left = ans;
		else right = ans;
	}
	printf("%.3f", ans);
}