#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include<cmath>
using namespace std;
//#6850_Cows
struct P { long long x, y; };
int N;
double ans;
vector<P> v, convex;
double dist(P a, P b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
int CCW(P a, P b, P c) {
    long long ret = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    return !ret ? 0 : (ret < 0 ? -1 : 1);
}
double cross(P a, P b, P c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
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
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) 
        cin>>v[i].x>>v[i].y;
    convex = ConvexHull();
    P st, u, v;
    st = convex[convex.size() - 1];
    u = convex[convex.size() - 2];
    for(int i=convex.size()-3;i>=0;i--) {
        v = convex[i];
        ans += 0.5 * abs((double)cross(st, u, v));
        u = v;
    }
    cout<<(int)(ans / 50);
}