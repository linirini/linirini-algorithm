#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//#7983_내일 할거야
int n,d,t;
vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d >> t;
        v.push_back({ t,d });
    }
    sort(v.begin(), v.end(),greater<>());
    int st = v[0].first-v[0].second;
    for (int i = 1; i < n; i++) {
        int d = v[i].second;
        int en = v[i].first + d - 1;
        if (v[i].first>st)st -= v[i].second;
        else st = v[i].first-v[i].second;
    }
    cout << st;
}
