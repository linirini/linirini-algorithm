#include<iostream>
#include<algorithm>
using namespace std;
//#11758_CCW
struct p {
	int x;
	int y;
};
p p1, p2, p3;
int main() {
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	int cp = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
	cp == 0 ? cout << 0 : cp > 0 ? cout << 1 : cout << -1;
}