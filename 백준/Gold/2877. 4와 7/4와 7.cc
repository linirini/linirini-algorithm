#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#2877_4와 7
int K;
vector<int>v;
int main() {
	cin >> K;
	int num = K+1;
	while (num > 0) {
		int tmp = num % 2;
		v.push_back(tmp);
		num /= 2;
	}
	reverse(v.begin(), v.end());
	v.erase(v.begin());
	for (auto i : v) {
		if (i == 1)cout << "7";
		else cout << "4";
	}
}