#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
pair<long long, long long> xp[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)cin >> xp[i].first >> xp[i].second;
    long long Max = xp[0].second;
    long long cost = Max;
    int flag = 0, fin = 0;
    for (int i = 1; i < N; i++) {
        if (!flag && i == N - 1) break;
        if (xp[i].first >= cost) {
            cost += xp[i].second;
            Max = max(Max, xp[i].second);
        }
        else {
            if (flag) {
                fin = true;
                break;
            }
            flag = true;
            if (xp[i].second < Max && cost - Max <= xp[i].first) {
                cost -= Max;
                if (xp[i].first < cost) {
                    fin = true;
                    break;
                }
                else {
                    cost += xp[i].second;
                }
            }
        }
    }
    fin ?cout<< "Zzz" : cout<<"Kkeo-eok";
    return 0;
}