#include<iostream>
#include<algorithm>
using namespace std;
//#17386_선분 교차 1
typedef pair<long long, long long> pll;
pll pos[4];
int ccw(pll pos1, pll pos2, pll pos3) {
	long long vecA = pos1.first * pos2.second + pos2.first * pos3.second + pos3.first * pos1.second;
	long long vecB = pos1.second * pos2.first + pos2.second * pos3.first + pos3.second * pos1.first;
	if (vecA - vecB > 0)return 1;
	if (vecA - vecB < 0)return -1;
	return 0;
}
int isCross() {
	return ccw(pos[0], pos[1], pos[2]) * ccw(pos[0], pos[1], pos[3]) < 0 && ccw(pos[2], pos[3], pos[0]) * ccw(pos[2], pos[3], pos[1]) < 0;
}
int main() {
	for (int i = 0; i < 4; i++) cin >> pos[i].first >> pos[i].second;
	cout << isCross();
}