#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#18116_로봇 조립
int N, a, b, c;
char cmd;
int parent[1000001],cnt[1000001];
bool flag;
int find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
        cnt[y] += cnt[x];
        cnt[x] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= 1000001; i++) {
        parent[i] = i;
        cnt[i]=1;
    }
    while (N--) {
        cin >> cmd;
        if (cmd == 'I') {
            cin >> a >> b;
            Union(a, b);
        }
        else {
            cin >> c;
            cout << cnt[find(c)]<<'\n';
        }
    }
}