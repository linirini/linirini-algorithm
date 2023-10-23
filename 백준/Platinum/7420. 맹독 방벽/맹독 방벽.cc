#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#define Pi 3.14159265358979
using namespace std;
//#7420_맹독 방벽
struct P { long long x, y; };
vector<P> v,convex;
int N, L;
double ans;
double dist(P a, P b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
int CCW(P a, P b, P c) {
    long long ret = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    //return <= 0 : NOT CCW 
    return !ret ? 0 : (ret < 0 ? -1 : 1);
}
bool cmp(P a, P b) {
    int chk = CCW(v[0], a, b);
    if (chk)return chk > 0 ? true : false;
    if (dist(v[0], a) < dist(v[0], b)) return true;
    return false;
}
vector<P> Graham() {
    for (int i = 0; i < N; i++) {
        while (2 <= convex.size() && CCW(convex[convex.size() - 2], convex[convex.size() - 1], v[i]) <= 0) {
            convex.pop_back();
        }
        convex.push_back(v[i]);
    }
    return convex;
}
vector<P> ConvexHull() {
    int idx = 0;
    for (int i = 1; i < N; i++) {
        if (v[idx].y > v[i].y || (v[idx].y == v[i].y && v[idx].x > v[i].x))idx = i;
    }
    swap(v[idx], v[0]);
    sort(v.begin() + 1, v.end(), cmp);
    vector<P>ret = Graham();
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N >> L;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].x >> v[i].y;
    convex = ConvexHull();
    P st = convex[convex.size() - 1];
    P u = convex[convex.size() - 1];
    P v;
    for(int i=convex.size()-2;i>=0;i--) {
        v =convex[i];
        ans += dist(u, v);
        u = v;
    }
    ans += dist(v, st);
    printf("%.0lf", ans + 2 * Pi * L);
}